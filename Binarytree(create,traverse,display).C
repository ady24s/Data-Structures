#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
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

    void preorder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        display(root);
        cout << endl;
    }

    void traverse(int type) {
        switch (type) {
            case 1:
                cout << "Preorder Traversal:" << endl;
                preorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Inorder Traversal:" << endl;
                display(root);  // Corrected this line to call display for inorder traversal
                cout << endl;
                break;
            case 3:
                cout << "Postorder Traversal:" << endl;
                postorder(root);
                cout << endl;
                break;
            default:
                cout << "Invalid traversal type" << endl;
                break;
        }
    }
};

int main() {
    BinaryTree tree;
    int numNodes, inputValue;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    if (numNodes <= 0) {
        cout << "Invalid number of nodes. Exiting." << endl;
        return 0;
    }

    cout << "Enter values for each node:" << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << (i + 1) << ": ";
        cin >> inputValue;
        tree.insert(inputValue);
    }

    for (int i=0; i<numNodes; i++){
    cout << "Choose a traversal type:" << endl;
    cout << "1. Preorder" << endl;
    cout << "2. Inorder" << endl;
    cout << "3. Postorder" << endl;

    int traversalType;
    cin >> traversalType;

    tree.traverse(traversalType);
    }

    return 0;
}
