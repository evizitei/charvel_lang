#include <string>

enum Token {
    tok_retire = -1, // eof
    tok_propose = -2,  // define
    tok_engage = -3,   // extern
    tok_title = -4,    // identifier
    tok_per_annum = -5 // number
};

static std::string TitleStr; // Filled in if tok_title
static double PerAnnumVal;        // Filled in if tok_per_annum

static int gettoken() {
    static int LastChar = ' ';
    while (isspace(LastChar))
        LastChar = getchar();
    if (isalpha(LastChar)) {
        TitleStr = LastChar;
        while (isalnum((LastChar = getchar())))
            TitleStr += LastChar;
        if (TitleStr == "propose") return tok_propose;
        if (TitleStr == "engage") return tok_engage;
        return tok_title;
    }
    if (isdigit(LastChar) || LastChar == '.') {   // Number: [0-9.]+
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');
        PerAnnumVal = strtod(NumStr.c_str(), 0);
        return tok_per_annum;
    }
}