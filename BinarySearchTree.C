#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void create(Node*& root, int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }

        if (value < root->data) {
            create(root->left, value);
        } else if (value > root->data) {
            create(root->right, value);
        }
    }

    void inOrderTraversal(Node* root) const {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

    void preOrderTraversal(Node* root) const {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void postOrderTraversal(Node* root) const {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->data << " ";
        }
    }

    void insertElement(int value) {
        create(root, value);
    }

    Node* findNode(Node* root, int key) const {
        if (root == nullptr || root->data == key) {
            return root;
        }

        if (key < root->data) {
            return findNode(root->left, key);
        }

        return findNode(root->right, key);
    }

    bool searchElement(int value) const {
        return findNode(root, value) != nullptr;
    }

    void mirrorTree(Node* root) const {
        if (root == nullptr) {
            return;
        }

        // Swap left and right subtrees for the current node
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively mirror the left and right subtrees
        mirrorTree(root->left);
        mirrorTree(root->right);
    }

    void mirror() {
        mirrorTree(root);
    }

    // Inside the BST class
    Node* copyTree(const Node* root) const {
        if (root == nullptr) {
            return nullptr;
        }

        // Create a new node with the same value
        Node* newNode = new Node(root->data);

        // Recursively copy the left and right subtrees
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);

        return newNode;
    }

    // Add this public method to the BST class
    BST copy() const {
        BST copiedTree;
        copiedTree.root = copyTree(root);
        return copiedTree;
    }
};

int main() {
    BST bst;

    // Take user input to build the BST
    cout << "Enter elements to insert into the BST (enter -1 to stop):\n";
    int value;
    while (true) {
        cout << "Enter element: ";
        cin >> value;

        if (value == -1) {
            break;
        }

        bst.insertElement(value);
    }

    cout << "Binary Search Tree created!\n";

    // Perform operations in a loop
    while (true) {
        // Prompt the user for operation type
        cout << "Choose an operation:\n";
        cout << "1. In-order Traversal\n";
        cout << "2. Pre-order Traversal\n";
        cout << "3. Post-order Traversal\n";
        cout << "4. Insert Element\n";
        cout << "5. Delete Element\n";
        cout << "6. Search Element\n";
        cout << "7. Mirror Tree\n";
        cout << "8. Copy Tree\n";
        cout << "9. Exit\n";

        int choice;
        cout << "Enter your choice (1, 2, 3, 4, 5, 6, 7, 8, or 9 to exit): ";
        cin >> choice;

        // Perform operation based on user choice
        switch (choice) {
            case 1:
                cout << "In-order traversal: ";
                bst.inOrderTraversal(bst.root);
                cout << "\n";
                break;
            case 2:
                cout << "Pre-order traversal: ";
                bst.preOrderTraversal(bst.root);
                cout << "\n";
                break;
            case 3:
                cout << "Post-order traversal: ";
                bst.postOrderTraversal(bst.root);
                cout << "\n";
                break;
            case 4:
                cout << "Enter element to insert: ";
                cin >> value;
                bst.insertElement(value);
                cout << "Element inserted!\n";
                break;
            // ...
            case 8:
                {
                    BST copiedTree = bst.copy();
                    cout << "BST copied!\n";
                    cout << "In-order traversal of copied tree: ";
                    copiedTree.inOrderTraversal(copiedTree.root);
                    cout << "\n";
                }
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}



 Node* findMin(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node with a given key from a subtree
    Node* bst deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        // Recursively find the node to be deleted
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Public method to delete an element
    void deleteElement(int value) {
        root = deleteNode(root, value);
    }
};