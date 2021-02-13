#include "Encoding.h"

/*
 * At the beginning, the function takes a tree's node (root) and normal text as a parameter
 * The last parameter str is initially a blank string and as the function goes left or goes right it add 0 and 1s to it
 * For example if the function goes right 3 times, str becomes 111
 * Firstly, the function always goes to the leftist side if it reaches a leaf, it stores the encoded str to the map
 * It uses the character as the key of the map and encoded str as value
 * If the given node is nullptr is returns and continues with the previous step
 */
void Encoding::encode(Node *root, string text, string str) {
    if(root != nullptr){
        if (root->isLeaf() && text.find(root->ch) != string::npos) {
            encodedChars[root->ch] = str;
        }
        encode(root->left, text, str + "0");
        encode(root->right, text,str + "1");
    }
}

/*
 * It does the same thing with the encode() function above
 * The difference is that, it takes a character instead of a whole text
 * If the functions finds wanted character in tree, it prints the encoded string
 */
void Encoding::encodeChar(Node *root, char character, string str){
    if(root != nullptr){
        if(root->isLeaf() && root->ch == character){
            cout << "Character '" << character << "' encoded form: " << str << endl;
            return;
        }
        encodeChar(root->left, character, str + "0");
        encodeChar(root->right, character,str + "1");
    }
}

/*
 * From encode() function, the function uses encodedChars[] map
 * For every character in the text, there is a corresponding encoded form
 * It uses the character from text
 * It collects whole word's characters in the encodedText (encodedText is initially empty)
 * After the for loop completes, it prints the encodedText
 */
void Encoding::generateCode(string text){
    for(char ch: text){
        encodedText += encodedChars[ch];
    }
    cout << encodedText << endl;
}