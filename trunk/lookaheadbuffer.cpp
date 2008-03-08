#include "lookaheadbuffer.h"

LookAheadBuffer::LookAheadBuffer(string sFileName)
{
    oScanner = new Scanner(sFileName);
    currToken = oScanner->getNextToken();
    lookAhead1 = oScanner->getNextToken();
    lookAhead2 = oScanner->getNextToken();

}

LookAheadBuffer::LookAheadBuffer()
{
}

LookAheadBuffer::~LookAheadBuffer()
{
    delete oScanner;
    delete currToken;
    delete lookAhead1;
    delete lookAhead2;
}

Token* LookAheadBuffer::getCurrentToken()
{
    return currToken;
}

Token* LookAheadBuffer::getLookAhead1()
{
    return lookAhead1;
}


Token* LookAheadBuffer::getLookAhead2()
{
    return lookAhead2;
}


void LookAheadBuffer::moveForward()
{
    lookAhead1 = lookAhead2;
    currToken = lookAhead1;
    lookAhead2 = oScanner->getNextToken();

}
