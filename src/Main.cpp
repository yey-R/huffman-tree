/*
 * The code is written with C++11 in Clion on Windows 10
 * So in order to execute it, to command line "g++ -std=c++11 *.cpp -o Main" should be written to build the project
 * Since there is file format difference between linux and windows
 * If the running system is linux, "dos2unix *" should also be written before execution
 * 1) dos2unix *
 * 2) g++ -std=c++11 *.cpp -o Main.exe
 */

/*
 * The launching can be:
 * ./Main.exe -i input_file.txt -encode (Encodes the given string from input file)
 * ./Main.exe -i input_file.txt -decode (Decodes the given encoded text from input file)
 * ./Main.exe -s char (Prints the given char's proper encoded form)
 * ./Main.exe -l (Shows the tree)
 */

#include "Command.h"
/*
 * Takes all arguments and collects them into 1 string
 * Creates a command class and sends the arguments to the its function
 */
int main(int argc, char *argv[]) {
    string command;
    for(int i =1; i < argc; i++){
        command += argv[i];
        command += "\n";
    }
    Command commands;
    commands.applyCommand(command);
    return 0;
}
