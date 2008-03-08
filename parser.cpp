#include "parser.h"
#include "rpal_constants.h"

//constructor
Parser::Parser()
{

}

Parser::Parser(string sFileName)
{
    oLookAhead = new LookAheadBuffer(sFileName);
    oStack = new Stack();
}

//destructor
Parser::~Parser()
{

}

bool Parser::Read(Token token)
{
    if (token.sToken != oLookAhead->getCurrentToken()->sToken)
    {
        return false;
    }
    if (token.eTokenType == IDENTIFIER || token.eTokenType == INTEGER || token.eTokenType == STRING)
    {
        oStack->buildTree(token.sToken, 0);
    }

    oLookAhead->moveForward();
    return true;
}

Token Parser::constructToken(string sToken, int eTokenType)
{
    Token tmpToken;
    tmpToken.eTokenType = eTokenType;
    tmpToken.sToken = sToken;

    return tmpToken;
}

//Methods

//#Expressions##############################

/*
E   -> ’let’ D ’in’ E => ’let’
    -> ’fn’ Vb+ ’.’ E => ’lambda’
    -> Ew;
*/
bool Parser::proc_E()
{
    if(oLookAhead->getCurrentToken()->sToken == TOKEN_LET)
    {
        Read(constructToken(TOKEN_LET, KEYWORD));

        proc_D();

        Read(constructToken(TOKEN_IN, KEYWORD));

        proc_E();
        oStack->buildTree(TOKEN_LET,2);

    }
    else if(oLookAhead->getCurrentToken()->sToken == TOKEN_FN)
    {

        Read(constructToken(TOKEN_FN, KEYWORD));

        int iNum = 0;
        do
        {
            proc_Vb();
            iNum++;
        }while((oLookAhead->getCurrentToken()->eTokenType == IDENTIFIER) || (oLookAhead->getCurrentToken()->sToken == TOKEN_OPEN_PARANTHESIS));

        Read(constructToken(".", KEYWORD));

        proc_E();

        oStack->buildTree(TOKEN_LAMBDA, iNum);
    }

    return true;
}


bool Parser::proc_Ew()
{

    proc_T();

    if (oLookAhead->getCurrentToken()->sToken == TOKEN_WHERE)
    {
        Read(constructToken(TOKEN_WHERE, KEYWORD));

        proc_Dr();

        oStack->buildTree(TOKEN_WHERE, 2);
    }

    return true;
}

//#Tuple Expressions##############################
bool Parser::proc_T()
{

    return true;
}

bool Parser::proc_Ta()
{

    return true;
}

bool Parser::proc_Tc()
{

    return true;
}

//#Boolean Expressions##############################
bool Parser::proc_B()
{

    return true;
}

bool Parser::proc_Bt()
{

 return true;
}

bool Parser::proc_Bs()
{

    return true;
}

bool Parser::proc_Bp()
{

    return true;
}

//#Arithmetic Expressions##############################
bool Parser::proc_A()
{

    return true;
}

bool Parser::proc_At()
{

    return true;
}

bool Parser::proc_Af()
{

    return true;
}

bool Parser::proc_Ap()
{


    return true;
}

//#Rators And Rands##############################
bool Parser::proc_R()
{

    return true;
}

bool Parser::proc_Rn()
{

    return true;
}

//#Definitions##############################
bool Parser::proc_D()
{

    proc_Da();

    if (oLookAhead->getCurrentToken()->sToken == TOKEN_WITHIN)
    {
        Read(constructToken(TOKEN_WITHIN, KEYWORD));

        proc_D();

        oStack->buildTree(TOKEN_WITHIN, 2);
    }

    return true;
}

bool Parser::proc_Da()
{
    proc_Dr();

    if (oLookAhead->getCurrentToken()->sToken == TOKEN_AND)
    {

        int iNum = 0;

        do
        {
            Read(constructToken(TOKEN_AND, KEYWORD));
            proc_Dr();

            iNum++;

        } while(oLookAhead->getCurrentToken()->sToken == TOKEN_AND);

        oStack->buildTree(TOKEN_AND, iNum);

    }

    return true;
}

bool Parser::proc_Dr()
{


    if (oLookAhead->getCurrentToken()->sToken == TOKEN_REC)
    {
        Read(constructToken(TOKEN_REC, KEYWORD));

        proc_Db();

        oStack->buildTree(TOKEN_REC, 1);
    }
    else
    {
        proc_Db();

    }

    return true;
}

bool Parser::proc_Db()
{

    if ((oLookAhead->getCurrentToken()->eTokenType == IDENTIFIER) && (oLookAhead->getLookAhead1()->sToken==TOKEN_EQUAL))
    {
        proc_Vl();

        Read(constructToken(TOKEN_EQUAL, KEYWORD));

        proc_E();

        oStack->buildTree(TOKEN_EQUAL, 2);
    }
    else if((oLookAhead->getCurrentToken()->eTokenType == IDENTIFIER) && ((oLookAhead->getLookAhead1()->eTokenType == IDENTIFIER) \
         || (oLookAhead->getLookAhead1()->sToken == TOKEN_OPEN_PARANTHESIS)))
    {
        int iNum;
        Read(*(oLookAhead->getCurrentToken()));

        do
        {
            proc_Vb();
            iNum++;

        }while(oLookAhead->getCurrentToken()->eTokenType == IDENTIFIER || oLookAhead->getCurrentToken == TOKEN_OPEN_PARANTHESIS);

        Read(constructToken(TOKEN_EQUAL, KEYWORD));

        proc_E();

        oStack->buildTree(TOKEN_FN_FORM, iNum + 2);

    }
    else
    {
        Read(constructToken(TOKEN_OPEN_PARANTHESIS, KEYWORD));

        proc_D();

        Read(constructToken(TOKEN_CLOSE_PARANTHESIS, KEYWORD));

    }
    return true;
}

//#Variables##############################
bool Parser::proc_Vb()
{

    if (oLookAhead->getCurrentToken()->eTokenType == IDENTIFIER)
    {
        Read(*(oLookAhead->getCurrentToken()));
    }
    else
    {
        Read(constructToken(TOKEN_OPEN_PARANTHESIS, KEYWORD));

        if (oLookAhead->getCurrentToken()->eTokenType == IDENTIFIER)
        {
            proc_Vl();
            Read(constructToken(TOKEN_CLOSE_PARANTHESIS, KEYWORD));
        }
        else
        {
            Read(constructToken(TOKEN_CLOSE_PARANTHESIS, KEYWORD));
            oStack->buildTree (TOKEN_OPEN_PARANTHESIS + TOKEN_CLOSE_PARANTHESIS, 0);
        }
    }

    return true;
}

bool Parser::proc_Vl()
{


    return true;
}

