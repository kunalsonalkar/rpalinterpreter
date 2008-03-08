#ifndef LOOKAHEADBUFFER_H_INCLUDED
#define LOOKAHEADBUFFER_H_INCLUDED

#include "scanner.h"

class LookAheadBuffer
{
    Token *currToken;
    Token *lookAhead1;
    Token *lookAhead2;

    Scanner* oScanner;

public:

    LookAheadBuffer();
    LookAheadBuffer(string sFileName);
    ~LookAheadBuffer();

    Token*   getCurrentToken();
    Token*   getLookAhead1();
    Token*   getLookAhead2();

    void moveForward();

};



#endif // LOOKAHEADBUFFER_H_INCLUDED
