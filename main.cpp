#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>

#include "VaderHandler.h"

using namespace std;

void withVarInit(string* vars);
void noVarInit();

bool findInVars(string* vars, string val);

bool art = true;

int main(int varc, string* vars) {
    if (varc > 1) withVarInit(vars);
    else noVarInit();
    VaderHandler handler;
    #ifdef WIN32
    system("cls");
    #else
    system("clear");
    #endif // WIN32
    if (art) {
        cout << handler.printColor(VaderHandler::PREFIXES::BOLD, VaderHandler::COLORS::RED) <<
                " _________________________________ " << endl <<
                "|:::::::::::::;;::::::::::::::::::|" << endl <<
                "|:::::::::::'~||~~~``:::::::::::::|" << endl <<
                "|::::::::'   .':     o`:::::::::::|" << endl <<
                "|:::::::' oo | |o  o    ::::::::::|" << endl <<
                "|::::::: 8  .'.'    8 o  :::::::::|" << endl <<
                "|::::::: 8  | |     8    :::::::::|" << endl <<
                "|::::::: _._| |_,...8    :::::::::|" << endl <<
                "|::::::'~--.   .--. `.   `::::::::|" << endl <<
                "|:::::'     =8     ~  \\ o ::::::::|" << endl <<
                "|::::'       8._ 88.   \\ o::::::::|" << endl <<
                "|:::'   __. ,.ooo~~.    \\ o`::::::|" << endl <<
                "|:::   . -. 88`78o/:     \\  `:::::|" << endl <<
                "|::'     /. o o \\ ::      \\88`::::|" << endl <<
                "|:;     o|| 8 8 |d.        `8 `:::|" << endl <<
                "|:.       - ^ ^ -'           `-`::|" << endl <<
                "|::.                          .:::|" << endl <<
                "|:::::.....           ::'     ``::|" << endl <<
                "|::::::::-'`-        88          `|" << endl <<
                "|:::::-'.          -       ::     |" << endl <<
                "|:-~. . .                   :     |" << endl <<
                "| .. .   ..:   o:8      88o       |" << endl <<
                "|. .     :::   8:P     d888. . .  |" << endl <<
                "|.   .   :88   88      888'  . .  |" << endl <<
                "|   o8  d88P . 88   ' d88P   ..   |" << endl <<
                "|  88P  888   d8P   ' 888         |" << endl <<
                "|   8  d88P.'d:8  .- dP~ o8       |" << endl <<
                "|      888   888    d~ o888       |" << endl <<
                "|_________________________________|" << endl <<
                handler.printColor(handler.RESET, handler.BLUE) << "Vader v1.0" << endl <<
                handler.printColor(handler.YELLOW) << "splash texts soon?" << endl << handler.printColor(handler.RESET);
        //cerr << "Error opening file" << endl;
    }

    while (true) {
        cout << handler.vaderText();
        string cmd, word;
        getline(cin, cmd);              // user input
        stringstream ss(cmd);           // modifiable stream
        vector<string> cmdVars;         // vector of command variables
        while (getline(ss, word, ' ')) {
            cmdVars.push_back(word);    // add every word of input to the cmdVars vector
        }
        if (cmdVars.size() > 0) cmdVars.erase(cmdVars.begin()); // remove cmd from vector
        handler.commandHandler(cmd, cmdVars);
    }

    return 0;
}

void withVarInit(string* vars) {
    for (int i = 0; i < sizeof(vars); ++i)
        for (int j = 0; j < vars[i].length(); ++j)
            tolower(vars[i][j]);

    if (findInVars(vars, "--help")) {
        string exe = "\"" + vars[0] + "\"";
        cout << exe << "        to run Vader CLI" << endl <<
                exe << "--noart to skip printing the ascii art." << endl <<
                exe << "--help  to print this screen";

        exit(0);
    }

    if (findInVars(vars, "--noart")) {
        art = false;
    }
}

bool findInVars(string* vars, string val) {
    for (int i = 0; i < sizeof(vars); ++i) {
        if (vars[i] == val) return true;
    }
    return false;
}

void noVarInit() { return; };
