#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

class scanner
{

    private:
        char* fileptr;
        ifstream filestream;
        int index, filesize;
        bool isoperator(int c);
        bool ispuncuation(int c);
        bool isEOF();

    public:
        scanner(char* name);
        ~scanner();
        string getnexttoken();

};

#endif // SCANNER_H_INCLUDED
