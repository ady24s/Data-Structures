#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void create() {
    int data;
    int n;

    cout << "";
    cin >> n;

    head = nullptr;
    Node* last = nullptr;

    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        Node* newNode = new Node(data);
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            last = newNode;
            head->next = head;
        } else {
            last->next = newNode;
            last = newNode;
            last->next = head;
        }
    }
}


  void display(){
    Node* temp = head;
    
    while (temp != NULL){
        cout << temp->data;
        if (temp->next != head){
            cout << "->";
        }
        temp = temp->next;
        
        if (temp == head) {
            break;
        }
    }
    
    cout << endl;
}
    void insertAtBeg(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            head->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            temp->next = head;
            head = temp;
            last->next = head;
        }
    }

    void insertAtEnd(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            head->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            last->next = temp;
            temp->next = head;
        }
    }

    void insertAtIntermediate(int position, int data) {
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

    void deleteAtIntermediate(int position) {
        if (head == nullptr) {
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

        while (count < position - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head) {
            cout << "Position exceeds the length of the list. Cannot delete." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void deleteAtBeg() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        if (temp->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            head = temp->next;
            delete temp;
            last->next = head;
        }
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head->next = prev;
    head = prev;
}


    void concatenateLists(Node* list2) {
    if (head == nullptr) {
        head = list2;
        return;
    }

    if (list2 == nullptr) {
        return;
    }

    Node* temp1 = head;
    while (temp1->next != head) {
        temp1 = temp1->next;
    }

    Node* temp2 = list2;
    while (temp2->next != list2) {
        temp2 = temp2->next;
    }

    temp1->next = list2;
    temp2->next = head;
    head = list2;
}
};

int main() {
    CircularLinkedList list;
    CircularLinkedList list2;

   cout << "Enter the number of elements in the list 1: ";
    list.create();

    cout << "Enter the number of elements in the list 2: ";
    list2.create();

    cout << "Circular Linked List 1: ";
    list.display();
    cout << "Circular Linked List 2: ";
    list2.display();

    int choice, data, position;

    while (true) {
        cout << "Circular Linked List Operations:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at an intermediate position" << endl;
        cout << "4. Delete a node at an intermediate position" << endl;
        cout << "5. Delete at Beginning" << endl;
        cout << "6. Delete at End" << endl;
        cout << "7. Display the linked list" << endl;
        cout << "8. Reverse Of the List" << endl;
        cout << "9. Concatenate Lists" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                list.insertAtBeg(data);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                list.insertAtEnd(data);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 3:
                cout << "Enter position and data to insert at an intermediate position: ";
                cin >> position >> data;
                list.insertAtIntermediate(position, data);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 4:
                cout << "Enter position to delete a node: ";
                cin >> position;
                list.deleteAtIntermediate(position);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 5:
                list.deleteAtBeg();
                cout << "Circular Linked List after deletion at beginning: ";
                list.display();
                break;
            case 6:
                list.deleteAtEnd();
                cout << "Circular Linked List after deletion at end: ";
                list.display();
                break;
            case 7:
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 8:
                cout << "Reverse List:";
                list.reverseList();
                list.display();
                break;
            case 9:
                list.concatenateLists(list2.head);
                cout << "Lists Concatenated." << endl;
                cout << "Concatenated List:";
                list.display();
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
