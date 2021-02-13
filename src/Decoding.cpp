#include "Decoding.h"


/*
 * Takes the root of the tree and encoded string as parameter
 * Inspects the strings one character by one character
 * If the current character is 0, then it goes to the left direction of the tree
 * If it is 1, then it goes to the right direction of the tree
 * Every time the function inspects a character from the string, it deletes the char from the original string
 * Until it reaches a leaf (in other word a character), it continues recursively
 * After finding, it prints the corresponding character
 * After printing, the function calls itself again with the root of the tree and the string left
 * The whole operation continues until the given string is totally empty and there is nothing to print
 */
void Decoding::decode(Node* node, string& str){
    do{
        if(node != nullptr){
            if(node->left == nullptr && node->right == nullptr){
                cout << node->ch;
                if(str.empty()){
                    cout << endl;
                }
                decode(root, str);
                return;
            }
            else if(!str.empty()) {
                char code = str[0];
                str = str.substr(1, str.size() - 1);
                if (code == '0') {
                    decode(node->left, str);
                } else {
                    decode(node->right, str);
                }
            }
        }
    }while(!str.empty());
}