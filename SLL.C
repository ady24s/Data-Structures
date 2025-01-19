#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
    data = value;
    next = NULL;
}

};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void sll create() {
        int data;
        int n;

        cout << "";
        cin >> n;

        head = nullptr;
        for (int i = 0; i < n; i++) {
            cout << "Enter data for node " << i + 1 << ": ";
            cin >> data;

            Node* newNode = new Node(data);
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }
    
    void sll display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

    void sll InsertAtBeg(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void sll insertAtTail(int data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = temp;
            return;
        }
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = temp;
    }

    void sll insertAtIntermediate(int position, int data) {
        Node* temp = head;
        int count = 1;

        while (count < position - 1) {
            temp = temp->next;
            count++;
        }

        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

    void sll deleteAtIntermediate(int position) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position - 1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL) {
            cout << "Position exceeds the length of the list. Cannot delete." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void sll deleteAtBeg() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void sll deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void sll reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }
     void sll concatenateLists(Node* list2) {
        if (head == NULL) {
            head = list2;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = list2;
    }
};

int main() {
    LinkedList list1, list2;

    cout << "Enter the number of elements in the list 1: ";
    list1.create();

    cout << "Enter the number of elements in the list 2: ";
    list2.create();

    cout << "Linked List 1: ";
    list1.display();
    cout << "Linked List 2: ";
    list2.display();

    int choice, data, position;

    while (true) {
        cout << "Linked List Operations:" << endl;
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
                cout << "Linked List: ";
                list1.display();
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                list1.insertAtTail(data);
                cout << "Linked List: ";
                list1.display();
                break;
             case 3:
                cout << "Enter position and data to insert at an intermediate position: ";
                cin >> position >> data;
                list1.insertAtIntermediate(position, data);
                cout << "Linked List: ";
                list1.display();
                break;
            case 4:
                cout << "Enter position to delete a node: ";
                cin >> position;
                list1.deleteAtIntermediate(position);
                cout << "Linked List: ";
                list1.display();

                break;
            case 5:
                list1.deleteAtBeg();
                cout << "Linked List after  deletion at beginning: ";
                list1.display();
                break;
            case 6:
                list1.deleteAtEnd();
                cout << "Linked List after deletion at end: ";
                list1.display();
                break;
            case 7:
                cout << "Linked List 1: ";
                list1.display();
                cout << "Linked List 2: ";
                list2.display();
                break;
            case 8:
                cout << "Reverse List 1:";
                list1.reverseList();
                list1.display();
                cout << "Reverse List 2:";
                list2.reverseList();
                list2.display();
                break;
            case 9:
                list1.concatenateLists(list2.head);
                cout << "Lists Concatenated." << endl;
                cout << "Concatenated List:";
                list1.display();

                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
