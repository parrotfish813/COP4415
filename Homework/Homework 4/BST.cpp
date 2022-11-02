/*
  Data Structures : COP4415.01
  Homework #4
  Brandon Townes
  Last modifed November 1st 2022
*/

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(){
      data = 0;
      left = NULL;
      right = NULL;
    }

    Node(int val){
      data = val;
      left = NULL;
      right = NULL;
    }
};


Node* insert(Node* root, Node* element);
void inOrder(Node* root);
int numNodes(Node* root);
int findKthSmallest(Node* root, int k);
int menu();

void inOrder(Node *currentPtr) {
  // Only traverse the node if it's not null.
  if(currentPtr != NULL) {
    inOrder(currentPtr->left); // Go Left.
    cout<<" "<<currentPtr->data; // Print the root.
    inOrder(currentPtr->right); // Go Right.
  }
}

//Gets a node and the root of the Binary search tree
//Insert the node into the BST
//Return the root after insertion
Node* insert(Node *root, Node *element) {

  // Inserting into an empty tree.
  if(root == NULL){
    return element;
  }

  else {

    // element should be inserted to the right.
    if(element->data > root->data) {

      // There is a right subtree to insert the node.
      if(root->right != NULL) {
        root->right = insert(root->right, element);
      }

      // Place the node directly to the right of root.
      else {
        root->right = element;
      }
    }

    // element should be inserted to the left.
    else {

      // There is a left subtree to insert the node.
      if(root->left != NULL) {
        root->left = insert(root->left, element);
      }

      // Place the node directly to the left of root.
      else {
        root->left = element;
      }
    }

    // Return the root pointer of the updated tree.
    return root;
  }
}

//Prints the inorder traversal of the tree pointed to by root
Node* findNode(Node *currentPtr, int value) {

  // Check if there are nodes in the tree.
  if(currentPtr != NULL) {

    // Found the value at the root.
    if(currentPtr->data == value) {
      return currentPtr;
    }

    // Search to the left.
    if(value < currentPtr->data) {
      return findNode(currentPtr->left, value);
    }

    // Or search to the right.
    else {
      return findNode(currentPtr->right, value);
    }

  }

  else {
    return NULL; // No node found.
  }
}


// Returns the number of nodes in the tree pointed to by root.
int numNodes(Node* root) {

  //If the tree is empty, return 0
  if(root == NULL) {
    return 0;
  }

  //Add together the number of nodes in the right tree and the number of nodes in the left tree, plus 1 since position 0
  return 1 + numNodes(root->left) + numNodes(root->right);

}

// Returns the kth smallest value in the BST pointed to by root
// Guaranteed that k is in between 1 and the number of nodes in the tree
// pointed to by root.
int findKthSmallest(Node* root, int k) {

  int sizeOfLeftSubtree = 0;

  //As long as it doesn't run into an empty node
  while(root != NULL) {

    //Get the size oof the left tree
    sizeOfLeftSubtree = numNodes(root->left);

    //If the given position is the first position, return data
    if (sizeOfLeftSubtree + 1 == k) {
      return root->data;
    }

    //If the given position is less than that of the left tree, check the right tree
    else if (sizeOfLeftSubtree < k) {
      root = root->right;
      k -= sizeOfLeftSubtree + 1;
    }

    //Otherwise, increment the position left
    else {
      root = root->left;
    }
  }

  return -1;

}

// Prints out the menu of choices for the user and returns their choice.
int menu() {

  int ans;
  cout<<"Here are your choices.\n";
  cout<<"1. Insert an item into your tree.\n";
  cout<<"2. Print out an in-order traversal.\n";
  cout<<"3. Print the number of the nodes. \n";
  cout<<"4. Finding kth smallest element.\n";
  cout<<"5. Exit.\n";
  cin>> ans;
  return ans;
}

int main() {

  Node *myRoot=NULL;
  Node* tempNode;
  int nNodes;
  int val;
  int ans;
  int rank;


  ans = menu();
  while (ans<5) {

    if (ans == 1) {

      // Get value to insert.
      cout<<"What value would you like to insert? ";
      cin>>val;
      tempNode = new Node(val); // Create the node.

      // Insert the value.
      myRoot = insert(myRoot, tempNode);
    }

    if (ans == 2) {

      // Print the values in tree.
      cout<<"Here is an in-order traversal of your tree: ";
      inOrder(myRoot);
      cout<<"\n";
    }


    if (ans == 3) {
      nNodes = numNodes(myRoot);
      cout << "There are " << nNodes << " nodes in the tree";
      cout<<"\n";
    }

    if (ans == 4) {
      cout<<"Which ranked item would you like to find?\n";
      cin>>rank;

      cout<<"The item is: "<< findKthSmallest(myRoot, rank);
      cout<<"\n";

    }

    // See if they want to insert more nodes.
    ans = menu();
  }

  
  return 0;
}