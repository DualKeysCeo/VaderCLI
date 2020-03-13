#ifndef VADERHANDLER_H
#define VADERHANDLER_H

#include <string>
#include <vector>
#include <stdarg.h>

using namespace std;

class VaderHandler {
    public:
        VaderHandler();
        ~VaderHandler();

        int commandHandler(string command, vector<string> cmdVars);
        static string printClrs(int code, ...);
        #define printColor(...) printClrs(__VA_ARGS__, 0x256)
        static string vaderText() { return (printColor(RESET, MAGENTA) + "VADER" + printColor(RESET) + "> "); }

        enum status {
            SUCCESS,
            WARNING,
            FAILURE
        };

        enum PREFIXES {
            RESET = 0,
            BRIGHT = 1,
            BOLD = 1,
            UNDERLINE = 4,
            INVERSE = 7,
            BOLDOFF = 21,
            UNDERLINEOFF = 24,
            INVERSEOFF = 27
        };

        enum COLORS {
            BLACK = 30,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            WHITE,
            BLACKBG = 40,
            REDBG,
            GREENBG,
            YELLOWBG,
            BLUEBG,
            MAGENTABG,
            CYANBG,
            WHITEBG
        };

        vector<string> getHistory() { return history; }
        void appendHistory(string val);

    protected:

    private:
        vector<string> history;
};

#endif // VADERHANDLER_H
