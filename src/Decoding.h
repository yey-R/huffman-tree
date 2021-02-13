#ifndef ASSIGNMENT4_DECODING_H
#define ASSIGNMENT4_DECODING_H

#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class Decoding {
public:
    Node* root; // Root of the tree
    Decoding() = default;
    void decode(Node* node, string& str); // Decoding operation
};


#endif //ASSIGNMENT4_DECODING_H
