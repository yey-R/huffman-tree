#ifndef ASSIGNMENT4_TREE_H
#define ASSIGNMENT4_TREE_H

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
#include "Node.h"

using namespace std;

class Tree {
public:
    Tree();
    Node* root;
    void buildTree(string text); // Takes original string, builds the tree
    void sort(vector<Node *> *list, unordered_map<char, int> map); // Sorts the chars with respect to their frequencies
    void createRoot(vector<Node *> &ch); // Creates nodes and assigns root
    void addNode(vector<Node *> *ch, Node *node); // Adds a new node to the ordered vector
    void restoreTree(); // Restores all tree from frequency table
    void displayTree(Node* root, int num); // Prints the current tree
    void writeFrequency(vector<Node*>* orderedCh); // Creates frequency_table.txt with respect to chars' frequencies order
};


#endif //ASSIGNMENT4_TREE_H
