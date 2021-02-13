#include "Command.h"

/*
 * Takes given 'argv' from Main and gives them a proper format
 * After formatting, applies given commands such as -decode -encode -l -s
 */
void Command::applyCommand(string command) {
    vector<string> operation = formatCommand(command, '\n');
    Tree tree;
    if(operation[0] == "-i"){
        ifstream inputFile;
        inputFile.open(operation[1]);
        string inputText;
        getline(inputFile, inputText);
        if(operation[2] == "-encode"){
            tree.buildTree(inputText);
            Encoding encoder;
            encoder.encode(tree.root, inputText, "");
            cout << "Normal string is: " << inputText << endl;
            cout << "Encoded string is: ";
            encoder.generateCode(inputText);
        }
        else if(operation[2] == "-decode"){
            tree.restoreTree();
            Decoding decoder;
            decoder.root = tree.root;
            cout << "Encoded string is: " << inputText << endl;
            cout << "Normal string is: ";
            decoder.decode(tree.root, inputText);
        }
    }
    else if(operation[0] == "-s"){
        Encoding encoder;
        tree.restoreTree();
        encoder.encodeChar(tree.root, operation[1][0], "");
    }
    else if(operation[0] == "-l"){
        tree.restoreTree();
        tree.displayTree(tree.root, 0);
    }

}

/*
 * Separates the given string with given separator
 * Returns divided string as a vector
 */
vector<string> Command::formatCommand(string strToSplit, char sep) {
    stringstream ss(strToSplit);
    string item;
    vector<string> sepString;
    while (getline(ss, item, sep)) {
        sepString.push_back(item);
    }
    return sepString;
}