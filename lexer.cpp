#include <string>

enum Token {
    tok_retire = -1, // eof
    tok_propose = -2,  // define
    tok_request = -3,   // extern
    tok_title = -4,    // identifier
    tok_per_annum = -5 // number
};

static std::string TitleStr; // Filled in if tok_title
static double PerAnnumVal;        // Filled in if tok_per_annum

static int get_next_token() {
    static int LastChar = ' ';
    while (isspace(LastChar))
        LastChar = getchar();
    if (isalpha(LastChar)) {
        TitleStr = LastChar;
        while (isalnum((LastChar = getchar())))
            TitleStr += LastChar;
        if (TitleStr == "propose") return tok_propose;
        if (TitleStr == "request") return tok_request;
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
    if(LastChar == '#') {
        // Comment until end of line.
        do
          LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');
        if (LastChar != EOF)
          return get_next_token();
    }
    if (LastChar == EOF)
        return tok_retire;
    
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}