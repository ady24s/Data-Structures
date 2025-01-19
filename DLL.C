#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void dll create() {
        int data;
        cout << "";
        int n;
        cin >> n;

        head = nullptr; // Start with an empty list

        for (int i = 0; i < n; i++) {
            cout << "Enter data for node " << i + 1 << ": ";
            cin >> data;

            Node* newNode = new Node(data);
            newNode->next = nullptr;
            newNode->prev = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
        }
    }

    void dll display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "<->";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void dll InsertAtBeg(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
    }

    void dll insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void dll insertAtIntermediate(int position, int data) {
        Node* newNode = new Node(data);
        if (position == 1) {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (count < position - 1 && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Position exceeds the length of the list. Cannot insert." << endl;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void dll deleteAtIntermediate(int position) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (count < position && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Position exceeds the length of the list. Cannot delete." << endl;
            return;
        }
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }

    void dll deleteAtBeg() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
    }

    void dll deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void dll reverseList() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void dll concatenateLists(Node* list2) {
        if (head == nullptr) {
            head = list2;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = list2;
        if (list2 != nullptr) {
            list2->prev = temp;
        }
    }
};

int main() {
    DoublyLinkedList list1, list2;

    cout << "Enter the number of elements in the list 1: ";
    list1.create();

    cout << "Enter the number of elements in the list 2: ";
    list2.create();

    cout << "Doubly Linked List 1: ";
    list1.display();
    cout << "Doubly Linked List 2: ";
    list2.display();

    int choice, data, position;

    while (true) {
        cout << "Doubly Linked List Operations:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at an intermediate position" << endl;
        cout << "4. Delete a node at an intermediate position" << endl;
        cout << "5. Delete at Beginning" << endl;
        cout << "6. Delete at End" << endl;
        cout << "7. Display the linked lists" << endl;
        cout << "8. Reverse Of the List" << endl;
        cout << "9. Concatenate Lists" << endl;
        cout << "10. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert at the beginning: ";
            cin >> data;
            list1.InsertAtBeg(data);
            cout << "Doubly Linked List: ";
            list1.display();
            break;
        case 2:
            cout << "Enter data to insert at the end: ";
            cin >> data;
            list1.insertAtTail(data);
            cout << "Doubly Linked List: ";
            list1.display();
            break;
        case 3:
            cout << "Enter position and data to insert at an intermediate position: ";
            cin >> position >> data;
            list1.insertAtIntermediate(position, data);
            cout << "Doubly Linked List: ";
            list1.display();
            break;
        case 4:
            cout << "Enter position to delete a node: ";
            cin >> position;
            list1.deleteAtIntermediate(position);
            cout << "Doubly Linked List: ";
            list1.display();
            break;
        case 5:
            list1.deleteAtBeg();
            cout << "Doubly Linked List after deletion at beginning: ";
            list1.display();
            break;
        case 6:
            list1.deleteAtEnd();
            cout << "Doubly Linked List after deletion at end: ";
            list1.display();
            break;
        case 7:
            cout << "Doubly Linked List 1: ";
            list1.display();
            cout << "Doubly Linked List 2: ";
            list2.display();
            break;
        case 8:
            cout << "Reverse Doubly Linked List 1:";
            list1.reverseList();
            list1.display();
            cout << "Reverse Doubly Linked List 2: ";
            list2.reverseList();
            list2.display();
            break;
        case 9:
            list1.concatenateLists(list2.head);
            cout << "Lists Concatenated" << endl;
            cout << "Concatenated List:";
            list1.display();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    return 0;
}
