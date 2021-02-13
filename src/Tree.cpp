#include "Tree.h"

Tree::Tree() {
    root = nullptr;
}

/*
 * Takes original text as input
 * Uses the chars from the text as keys of an unordered map
 * Calculates their frequencies
 * Creates a vector called orderedCh and calls sorting with it
 * After storing the chars in the vector in an ordered way
 * Calls createRoot() function with the vector
 */
void Tree::buildTree(string text) {
    unordered_map<char, int> chMap;
    for(char ch: text){
        chMap[ch]++;
    }
    vector<Node*> orderedCh;
    sort(&orderedCh, chMap);
    createRoot(orderedCh);
}

/*
 * Takes a vector, which is ordered with respect to chars frequency (low to high), as parameter
 * Creates nodes with its elements and adds them to itself
 * Everytime the loop repeats, it takes 2 elements and create 1 node with them, so the size decreases
 * It continues until the size of the vector is 1
 * When the size of the vector is 1, the element that is left in the vector is the root of the tree
 * Assigns it to the root
 */
void Tree::createRoot(vector<Node*>& ch){
    int counter = 0;
    while(ch.size() != 1){
        Node* leftNode = ch.front();
        ch.erase(ch.begin());
        Node* rightNode = ch.front();
        ch.erase(ch.begin());
        int sum = leftNode->freq + rightNode->freq;
        Node* newNode = new Node('.',sum, leftNode, rightNode);
        addNode(&ch, newNode);
    }
    root = ch.front();
}

/*
 * Takes an empty vector and unordered map, which is filled with 'char, int' pairs, as parameter
 * Creates a new node with every char, int pair and adds them to the vector with respect to their frequency
 * The frequencies are ordered the lowest to the highest
 */
void Tree::sort(vector<Node*>* list, unordered_map<char, int> map) {
    for (auto pair: map) {
        Node *newNode = new Node(pair.first, pair.second);
        if (list->empty()) {
            list->push_back(newNode);
        } else {
            int counter = 0;
            for (Node *temp: *list) {
                if (temp->freq < newNode->freq) {
                    counter++;
                }
            }
            list->insert(list->begin()+counter, newNode);
        }
    }
    writeFrequency(list);
}

/*
 * Adds new nodes with proper order with respect to its frequency
 */
void Tree::addNode(vector<Node*>* list, Node* node){
    int counter = 0;
    for (Node *temp: *list) {
        if (temp->freq < node->freq) {
            counter++;
        }
    }
    list->insert(list->begin()+counter, node);
}

/*
 * With a frequency table, it re-creates the tree
 * It reads the frequency table from a txt file and creates an ordered vector
 * After that it calls createRoot() function
 */
void Tree::restoreTree() {
    vector<Node*> orderedCh;
    ifstream freqFile;
    freqFile.open("freq_table.txt");
    string str;
    while(getline(freqFile, str)){
        Node* newNode = new Node(str[0], atoi(str.substr(2,1).c_str()));
        orderedCh.push_back(newNode);
    }
    freqFile.close();
    createRoot(orderedCh);
}

/*
 * Prints the tree
 * It begins with root and goes to the most right hand side and goes left step by step
 * When there are 2 leaf or parents at the same level
 * The upper side is always right side of the tree and the down side is always left side of the tree
 * For example:
 * +==Root (frequency)
 *    +==Right (frequency)
 *    |  +==Right (frequency)
 *    |  |  +== Right (frequency) (char)
 *    |  |  +== Left (frequency) (char)
 *    |  +==Left (frequency) (char)
 *    +==Left (frequency)
 *    |  +==Right (frequency)
 *    |  |  +==Right (frequency) (char)
 *    |  |  +==Left (frequency) (char)
 *    |  +==Left (frequency) (char)
 *
 *    The | indicator shows belongings, if there is a | symbol under +==, until the another part the elements between
 *    belongs to the upper +==
 *    If a node is not a leaf, it just prints its frequency
 */
void Tree::displayTree(Node* node, int num){
    if(node != nullptr){
        for(int i = 0; i < num; i++){
            cout << " ";
            if(num > 3 && i % 3 == 2 && i != num-1){
                cout << "|";
            }
        }
        cout <<  "+==" << "(" << node->freq << ")";
        if(node->isLeaf()){
            if(node->ch == ' '){
                cout << '"';
            }
            else{
                cout << node->ch;
            }
        }
        cout << endl;
        displayTree(node->right, num+3);
        displayTree(node->left, num+3);
    }
}

/*
 * Creates a frequency_table.txt after a tree creation operation
 * The purpose of creating a txt file is that
 * After encoding a text and the code finishes its run, if the user tries re-launch the program
 * For decoding, displaying tree or a character encoding
 * The code first reads the frequency_table.txt and re-creates the tree
 * To make that happen, after first encoding operation, the code creates the frequency_table.txt
 * So it can remember the tree
 */
void Tree::writeFrequency(vector<Node*>* orderedCh){
    ofstream output;
    output.open("freq_table.txt");
    for(auto ch: *orderedCh){
        output << ch->ch << " " << ch->freq << endl;
    }
    output.close();
}