#ifndef ASSIGNMENT4_ENCODING_H
#define ASSIGNMENT4_ENCODING_H

#include <fstream>
#include <iostream>
#include <unordered_map>
#include "Node.h"

using namespace std;

class Encoding {
public:
    string encodedText;
    unordered_map<char, string> encodedChars;
    void encode(Node *root, string text, string str); // Encoding operation of a whole text
    void encodeChar(Node *root, char character, string str); // Encoding operation of a character
    void generateCode(string text); // Gives output of wanted string
};


#endif //ASSIGNMENT4_ENCODING_H
