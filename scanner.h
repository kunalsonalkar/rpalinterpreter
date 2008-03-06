#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

struct Token{
    string sNextToken;
    int eTokenType;
};

class Scanner
{

    private:
        char* fileptr;
        Token* ptrToken;
        ifstream filestream;
        int index, filesize;
        bool isoperator(int c);
        bool ispuncuation(int c);
        bool isEOF();

    public:
        Scanner(string name);
        ~Scanner();
        Token* getNextToken();

};

#endif // SCANNER_H_INCLUDED
