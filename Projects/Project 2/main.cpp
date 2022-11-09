/*
  Data Structures : COP4415.01
  Homework #4
  Brandon Townes
  Last modifed November 1st 2022
*/

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

FILE *outfile = fopen("out.txt", "r");

//For the items of each tree Name
class itemNode {
  public:
    char name[50];
    int count;

  itemNode *left, *right;

  itemNode() {
    name[0]='\0';
    count = 0;
    left = NULL;
    right = NULL;
  }

  itemNode(char itemName[], int population) {
    strcpy(name, itemName);
    count = population;
    left = NULL;
    right = NULL;
  }
};

//For Tree Names
class treeNameNode {
  public:
    char treeName[50];
    treeNameNode *left, *right;
    itemNode *theTree;

  treeNameNode() {
    treeName[0]='\0';
    theTree = NULL;
    left = NULL;
    right = NULL;
  }

  treeNameNode(char name[]) {
    strcpy(treeName, name);
    theTree = NULL;
    left = NULL;
    right = NULL;
  }
};

void inOrder_treeNameTree(treeNameNode *currentPtr) {
  // Only traverse the node if it's not null.
  if(currentPtr != NULL) {
    inOrder_treeNameTree(currentPtr->left); // Go Left.
    cout << " " << currentPtr; // Print the root.
    inOrder_treeNameTree(currentPtr->right); // Go Right.
  }
}


//Gets a node and the root of the Binary search tree
//Insert the node into the BST
//Return the root after insertion
itemNode* insertItemNode(itemNode* root, itemNode* element) {

}

treeNameNode* insertTreeNameTree(treeNameNode* root, treeNameNode* element) {

}

// Returns the number of nodes in the tree pointed to by root.
int numNodes(itemNode* root) {

  //If the tree is empty, return 0
  if(root == NULL) {
    return 0;
  }

  //Add together the number of nodes in the right tree and the number of nodes in the left tree, plus 1 since position 0
  return 1 + numNodes(root->left) + numNodes(root->right);

}

treeNameNode *buildNameTree(FILE *infile, int tinCount) {
  treeNameNode *topTree = NULL;
  char treeName[50];

  for(int i = 0; i < tinCount; i++) {
    fscanf(infile, "%s", treeName);
    treeNameNode *temp = new treeNameNode(treeName);
    topTree = insertTreeNameTree(topTree, temp);
  }

  return topTree;
}


void buildOtherTrees( FILE *infile, treeNameNode *topTree, int itemCount ) {
  char treeName[50], itemName[50];
  treeNameNode *foundTopTree;
  int population;

  for(int i = 0; i < itemCount; i++) {

    fscanf(infile, "%s %s %d", treeName, itemName, &population);


  }
}

void traverse_in_traverse(treeNameNode *root) {
  if(root != NULL) {
    
  }

}

int search(treeNameNode *root, char *paramA, char *paramB, int *paramC) {

}

treeNameNode *searchNameNode(treeNameNode *root, char treeName[50]) {

}

void item_before() {

}

void right_balance() {

}

void count() {
  
}

void performQueries(treeNameNode *topTree, FILE *inFile, int queryCount) {

  FILE *infile = fopen("in.txt", "r");
  treeNameNode *root;
  char *queryType;

  char paramA[50];
  char paramB[50];
  int paramC;

  for(int i = 0; i < queryCount; i++) {
    fscanf(inFile, "%s", queryType);

    if(strcmp(queryType, "search") == 0) { 
      fscanf(inFile, "%s %s", paramA, paramB);
      int res = search(root, paramA, paramB, &paramC);
      
      if(res == 0) {
        cout << "%d %s found in %s\n" << paramC << paramB << paramA << endl;
        fprintf(outfile, "%d %s found in %s\n", paramC, paramB, paramA);
      }

      else if(res == -1) {
        cout << "%d %s does not exist\n" << paramA << endl;
        fprintf(outfile, "%d %s does not exist\n", paramA);
      }

      else if(strcmp(queryType, "item_before") == 0) {
        fscanf(infile, "%s %s", paramA, paramB);


      }

      else if(strcmp(queryType, "height_balance") == 0) {
        fscanf(infile, "%s", paramA);


      }

      else if(strcmp(queryType, "count") == 0) {

        
      }

      else {

      }
    }
  }

}

int main() {

  FILE *infile = fopen("in.txt", "r");
  outfile = fopen("out.txt", "w");
  treeNameNode *topTree = NULL;

  int tnCount, itemCount, queryCount;
  fscanf(infile, "%d %d %d", &tnCount, &itemCount, &queryCount);

  topTree = buildNameTree(infile, itemCount);
  buildOtherTrees(infile, topTree, itemCount);

  inOrder_treeNameTree(topTree);

  cout << endl;

  fprintf(outfile, "\n");
  traverse_in_traverse(topTree);

  performQueries(topTree, infile, queryCount);

  fclose(outfile);

  return 0;
}