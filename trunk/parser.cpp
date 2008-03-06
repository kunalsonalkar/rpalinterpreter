#include "parser.h"
#include "rpal_constants.h"

//constructor
Parser::Parser()
{

}

Parser::Parser(string sFileName)
{
    oScanner = new Scanner(sFileName);
    oStack = new Stack();
}

//destructor
Parser::~Parser()
{
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
    if(oScanner->getNextToken()->sNextToken == TOKEN_LET)
    {
        proc_D();

        if(oScanner->getNextToken()->sNextToken == TOKEN_IN)
        {
            proc_E();
            oStack->buildTree(TOKEN_LET,2);
        }
        else
            return false;
    }
    else if(oScanner->getNextToken()->sNextToken == TOKEN_FN)
    {
        int iNum = 0;
        do
        {
            proc_Vb();
            iNum++;
        }while(true);
    }
    return true;
}

bool Parser::proc_Ew()
{

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

    return true;
}

bool Parser::proc_Da()
{

    return true;
}

bool Parser::proc_Dr()
{

    return true;
}

bool Parser::proc_Db()
{

    return true;
}

//#Variables##############################
bool Parser::proc_Vb()
{

    return true;
}

bool Parser::proc_Vl()
{

    return true;
}

