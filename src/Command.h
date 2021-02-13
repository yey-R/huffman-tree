#ifndef ASSIGNMENT4_COMMAND_H
#define ASSIGNMENT4_COMMAND_H

#include <sstream>
#include "Decoding.h"
#include "Encoding.h"
#include "Tree.h"

using namespace std;

class Command {
public:
    void applyCommand(string command); // Applies the given command
    vector<string> formatCommand(string strToSplit, char sep); // Separates the given string with given separator
};


#endif //ASSIGNMENT4_COMMAND_H
