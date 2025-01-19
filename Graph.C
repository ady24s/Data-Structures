#include <iostream>
using namespace std;

const int MAX = 100;

class graphnode {
public:
    int vertex;
    graphnode *next;

    graphnode(int n = 0) : vertex(n), next(nullptr) {}
};

class listgraph {
    graphnode *list[MAX];
    int n;

public:
    listgraph(int nov) : n(nov) {
        for (int j = 0; j < n; j++)
            list[j] = nullptr;
    }

    void create() {
    char ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\nIs there an edge between vertex " << i + 1 << " and "
             << j + 1 << "? (y/n): ";
            cin >> ans;

            if (ans == 'y') {
                graphnode *newnode = new graphnode(j + 1);

                // Attach newnode to list i
                if (list[i] == nullptr)
                    list[i] = newnode;
                else {
                    graphnode *temp = list[i];
                    while (temp->next != nullptr)
                        temp = temp->next;
                    temp->next = newnode;
                }
            }
        }
    }
}
    void display() {
    for (int i = 0; i < n; i++) {
        cout << "\nVertex " << i + 1 << " -> ";
        graphnode *temp = list[i];

        while (temp != nullptr) {
            cout << "v" << temp->vertex << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }

}

void insertNode(int vertex, int connectedVertex) {
    graphnode *newnode = new graphnode(connectedVertex);

    // Attach newnode to list vertex
    if (list[vertex - 1] == nullptr)
        list[vertex - 1] = newnode;
    else {
        graphnode *temp = list[vertex - 1];
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newnode;
    }
}

void deleteNode(int vertex, int connectedVertex) {
    graphnode *current = list[vertex - 1];
    graphnode *prev = nullptr;

    while (current != nullptr && current->vertex != connectedVertex) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\nEdge between v" << vertex << " and v" << connectedVertex << " not found.";
        return;
    }

    if (prev == nullptr) {
        // If the node to be deleted is the first node in the list
        list[vertex - 1] = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "\nEdge between v" << vertex << " and v" << connectedVertex << " deleted.";
}

};

int main() {
    int n, deleteVertex, deleteConnectedVertex;
    cout << "Enter the number of vertices: ";
    cin >> n;

    listgraph g(n);
    g.create();

    g.display();

    cout << "\nEnter the vertex to delete from: ";
    cin >> deleteVertex;

    cout << "Enter the connected vertex to delete: ";
    cin >> deleteConnectedVertex;

    g.deleteNode(deleteVertex, deleteConnectedVertex);

    g.display();

    return 0;
}
