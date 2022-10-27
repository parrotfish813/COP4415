#include <iostream>
#include <ctype.h>

using namespace std;

class Node {
    public:
        int key;
        Node *left;
        Node *right;
        int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *N) {
    if(N == NULL) {
        return 0;
    }
    return N->height;
}

Node* newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
}

int getBalance(Node *N) {
    if(N == NULL) {
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node* rightRotate(Node *C) {
    Node* B = C->left;
    Node* T2 = B->right;

    B->right = C;
    C->left = T2;

    C->height = 1 + max(height(C->left), height(C->right));
    B->height = 1 + max(height(B->left), height(B->right));

    return B;
}

Node* leftRotate(Node *X) {
    Node* Y = X->right;
    Node* T2 = Y->left;

    Y->left = X;
    X->right = T2;

    X->height = 1 + max(height(X->left), height(X->right));
    Y->height = 1 + max(height(Y->left), height(Y->right));

    return Y;
}

Node *insert(Node *node, int key) {
    if(node == NULL) {
        return newNode(key);
    }
    if(key < node->key) {
        node->left = insert(node->left, key);
    }
    else if(key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if(balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    if(balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    if(balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < 1 && key < node->right->key) {
        node->left = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() {

    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << root << endl;

    return 0;
}
