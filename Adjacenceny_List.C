#include <iostream>
using namespace std;

const int MAX = 100; // Adjust the maximum number of vertices as needed

class graphnode {
public:
    int vertex;
    graphnode *next;

    graphnode(int n = 0) : vertex(n), next(nullptr) {}
};

class listgraph {
    graphnode *list[MAX]; // array of pointers
    int n; // number of vertices

public:
    listgraph(int nov) : n(nov) {
        for (int j = 0; j < n; j++)
            list[j] = nullptr;
    }

    void create();
    void display();
};

void listgraph::create() {
    int i, j;
    graphnode *temp, *newnode;
    char ans;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "\nIs there an edge between vertex " << i + 1 << " and " << j + 1 << "? ";
            cin >> ans;

            if (ans == 'y') {
                newnode = new graphnode(j + 1); // call constructor

                // Attach newnode to list i
                if (list[i] == nullptr)
                    list[i] = temp = newnode;
                else {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }
}

void listgraph::display() {
    graphnode *temp;
    int i;

    for (i = 0; i < n; i++) {
        cout << endl;
        cout << "Vertex " << i + 1 << "->";

        temp = list[i];

        while (temp != nullptr) {
            cout << "v" << temp->vertex << "->";
            temp = temp->next;
        }

        cout << "NULL";
    }
}

int main() {
    int vertices;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    listgraph graph(vertices);
    graph.create();

    cout << "\nAdjacency List representation of the graph:\n";
    graph.display();

    return 0;
}
