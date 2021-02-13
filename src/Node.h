#ifndef ASSIGNMENT4_NODE_H
#define ASSIGNMENT4_NODE_H

struct Node{
    int freq; // The number of how many times the character appears in the text
    char ch; // The given character
    Node* left; // Left child
    Node* right; // Right child
    Node(char ch, int freq, Node *left= nullptr, Node *right = nullptr) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
    /*
     * Checks if the current node is a leaf or not
     * Returns true if it is
     */
    bool isLeaf(){
        return this->left == nullptr && this->right == nullptr;
    }
};




#endif //ASSIGNMENT4_NODE_H
