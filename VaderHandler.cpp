#include "VaderHandler.h"
#include <algorithm>
#include <iostream>

VaderHandler::VaderHandler()
{
    //ctor
}

VaderHandler::~VaderHandler()
{
    //dtor
}

void VaderHandler::appendHistory(string val) { history.push_back(val); }

int VaderHandler::commandHandler(string command, vector<string> cmdVars) {
    appendHistory(command);
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "exit" || command == "quit") { exit(0); return VaderHandler::FAILURE; }
    if (command == "trello") { cout << "Vader's Trello Board can be found here:" << endl << "\thttps://trello.com/b/qjI699K2/vader" << endl; }
    return VaderHandler::SUCCESS;
}

string VaderHandler::printClrs(int code, ...) {
    va_list args;
    string returnStr = "\033[";
    for (va_start(args, code); code != 0x256; code = va_arg(args, int)) {
        returnStr += (to_string(code) + ';');
    }
    va_end(args);
    returnStr.pop_back();
    returnStr += 'm';
    return returnStr;
}
