#include <iostream>

using namespace std;

struct Node {
    public:
        int data;
        struct Node *left, *right;
    Node();
    Node(int);
    Node *Insert(Node *, int);
    Node *minValueNode(Node *);
    Node *deleteNode(Node *, int);
    void inOrder(Node *);
};

// Insert function definition
Node *Node::Insert(Node *root, int value) {
    if(root == NULL) {
        Node *newNode = new Node(value);
        return newNode;
    }

    if(value > root->data) {
        root->right = Insert(root->right, value);
    }

    if(value < root->data) {
        root->left = Insert(root->left, value);
    }

    return root;
    }

// deleteNode function definition
Node *Node::deleteNode(Node *root, int value) {
    if(root == NULL) {
        return nullptr;
    }
    
    if(value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    else if(value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    else {
        if(root->left == NULL && root->right == NULL) {
            return nullptr;
        }

        else if(root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// minValueNode function definition
Node *Node::minValueNode(Node *root) {
    if(root->left == NULL) {
        return root;
    }

    else {
        return minValueNode(root->left);
    }
}

int main() {

}