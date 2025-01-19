#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        } else {
            if (value < node->data) {
                node->left = insert(node->left, value);
            } else {
                node->right = insert(node->right, value);
            }
            return node;
        }
    }

    void display(TreeNode* node) {
        if (node != nullptr) {
            display(node->left);
            cout << node->data << " ";
            display(node->right);
        }
    }

    TreeNode* copyTree(TreeNode* originalNode) {
        if (originalNode == nullptr) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(originalNode->data);
        newNode->left = copyTree(originalNode->left);
        newNode->right = copyTree(originalNode->right);

        return newNode;
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void create() {
        int numNodes, inputValue;

        cout << "Enter the number of nodes: ";
        cin >> numNodes;

        if (numNodes <= 0) {
            cout << "Invalid number of nodes." << endl;
            return;
        }

        cout << "Enter values for each node:" << endl;

        for (int i = 0; i < numNodes; ++i) {
            cout << "Node " << (i + 1) << ": ";
            cin >> inputValue;
            root = insert(root, inputValue);
        }
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        display(root);
        cout << endl;
    }

    BinaryTree copy() {
        BinaryTree newTree;
        newTree.root = copyTree(root);
        return newTree;
    }

    void search(int value) {
        search(root, value);
    }

    void search(TreeNode* node, int value) {
    if (node == nullptr) {
        cout << "Value not found in the tree." << endl;
    } else if (value == node->data) {
        cout << "Value found in the tree." << endl;
    } else if (value < node->data) {
        search(node->left, value);
    } else {
        search(node->right, value);
    }
}

// Add these public functions to the BinaryTree class
void deleteNode(int value) {
    root = deleteNode(root, value);
}

// Add these private functions to the BinaryTree class
TreeNode* deleteNode(TreeNode* node, int value) {
    if (node == nullptr) {
        cout << "Value not found in the tree." << endl;
        return node;
    }

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        // Node with only one child or no child
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            cout << "Value deleted from the tree." << endl;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            cout << "Value deleted from the tree." << endl;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;

    // Find the leftmost leaf
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

};

int main() {
    BinaryTree tree;
    int choice, inputValue;
    tree.create();
    cout << "Binary Search Tree:" << endl;
    tree.display();

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Insert an element" << endl;
        cout << "2. Copy the tree" << endl;
        cout << "3. Display the tree" << endl;
        cout << "4. Search for an element " << endl;
        cout << "5. Delete the element" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> inputValue;
                tree.insert(inputValue);
                tree.display();
                break;
            case 2: {
                BinaryTree copiedTree = tree.copy();
                cout << "Copied Binary Search Tree:" << endl;
                copiedTree.display();
                break;
            }
            case 3:
                cout << "Binary Search Tree:" << endl;
                tree.display();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> inputValue;
                tree.search(inputValue);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> inputValue;
                tree.deleteNode(inputValue);
                tree.display();
                break;

            case 6:
                cout << "Exiting." << endl;
                break;


            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
