#include <iostream>
using namespace std;

const int MAX = 100; // Adjust the maximum number of vertices as needed

class matrixgraph {
    int matrix[MAX][MAX]; // 2D array for adjacency matrix
    int n; // number of vertices

public:
    matrixgraph(int nov) : n(nov) {
        // Initializing the matrix with 0
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;
    }

    void create();
    void display();
};

void matrixgraph::create() {
    int i, j;
    char ans;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "\nIs there an edge between vertex " << i + 1 << " and " << j + 1 << "? ";
            cin >> ans;

            if (ans == 'y') {
                // Set the corresponding entry in the matrix to 1
                matrix[i][j] = 1;
            }
        }
    }
}

void matrixgraph::display() {
    int i, j;

    for (i = 0; i < n; i++) {
        cout << endl;
        cout << "Vertex " << i + 1 << "->";

        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                cout << "v" << j + 1 << "->";
            }
        }

        cout << "NULL";
    }
}

int main() {
    int vertices;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    matrixgraph graph(vertices);
    graph.create();

    cout << "\nAdjacency Matrix representation of the graph:\n";
    graph.display();

    return 0;
}
