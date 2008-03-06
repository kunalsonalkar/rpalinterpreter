#include "scanner.h"
#include "rpal_constants.h"
using namespace std;


Scanner::Scanner(string name)
{
    //objToken = new Token();
    ptrToken = (Token*)malloc(sizeof(Token));

    filestream.open(name.c_str(), ios::in|ios::ate);

    if (!filestream)
    {
        cout<<"Cannot open input file " << name << "!!"<<endl<<"Exiting.."<<endl;
        exit(1);
    }

    filesize = (int) filestream.tellg();

    fileptr = new char[filesize];

    filestream.seekg(0, ios::beg);

    filestream.read(fileptr,filesize);

    filestream.close();

    index = 0;

}

Scanner::~Scanner()
{

    delete fileptr;

}

bool Scanner::isEOF()
{
    return (index < filesize) ? false : true;
}

Token* Scanner::getNextToken()
{
    string currtoken = "";

    if (index >= filesize)
    {
        ptrToken->sNextToken = "";
        ptrToken->eTokenType = END_OF_FILE;

        return ptrToken;
    }

    while (index < filesize)
    {
        char currchar = fileptr[index];


        /*
            Check for identifier tokens
            Identifier -> Letter (Letter | Digit | ’_’)* => ’<IDENTIFIER>’;
            Notes: ge, le which are keywords will be detected as an ID in the Scanner. Parser should work on it
        */

        //suspect: change all ifs to if-elseifs ?
        if (isalpha(currchar))
        {
            do
            {
                currtoken += fileptr[index];
                index++;
            } while ( !isEOF() && (fileptr[index] == '_') || isalpha(fileptr[index]) || isdigit(fileptr[index]) );

            ptrToken->sNextToken = currtoken;
            ptrToken->eTokenType = IDENTIFIER;

            return ptrToken;
        }

        /*
            Check for digits
            Integer ->Digit+ =>’<INTEGER>’;
        */

        else if (isdigit(currchar))
        {
            do
            {
                currtoken += fileptr[index];
                index++;
            } while ( !isEOF() && isdigit(fileptr[index]) );

            ptrToken->sNextToken = currtoken;
            ptrToken->eTokenType = INTEGER;

            return ptrToken;
        }


        /*
            Extract operator tokens
            Operator -> Operator_symbol+ => ’<OPERATOR>’;
        */

        else if (isoperator(currchar) && !(currchar == '/' && fileptr[index+1] == '/'))
        {
            do
            {
                currtoken += fileptr[index];
                index++;
            } while ( !isEOF() && isoperator(fileptr[index]) );

            ptrToken->sNextToken = currtoken;
            ptrToken->eTokenType = OPERATOR;

            return ptrToken;

        }

        /*
            Extract string literals
        */
        else if (currchar == '\'')
        {
            index++;
            do
            {
                currtoken += fileptr[index];
            } while( !isEOF() && (currchar = fileptr[index++]) != '\'');

            currtoken += currchar; //suspect : what about the last char in the string? and why is currchar assigned to currtoken

            ptrToken->sNextToken = currtoken;
            ptrToken->eTokenType = STRING;

            return ptrToken;
        }

        /*
            Bypass spaces and tabs
            Spaces -> ( ’ ’ | ht | Eol )+ => ’<DELETE>’;
        */

        else if( isspace(currchar) || currchar == '\t' || currchar == '\n' ) //suspect : what about End of Line. isn't is \n\r ?
        {
            index++;
        }

        /*
            If a comment (//) is found, skip the characters
            until a end of line character is encountered.
        */

        else if(currchar=='/' && fileptr[++index] == '/')
        {
            while( (fileptr[++index] != '\n') );//suspect : what about End of Line. isn't is \n\r ?
        }

        /*
            Extract punctuations
        */

        else if ( ispuncuation(currchar) )
        {
            currtoken += currchar;
            index++;

            ptrToken->sNextToken = currtoken;
            ptrToken->eTokenType = PUNCTUATION;

            return ptrToken;

        }

        else
        {
           return NULL; //Handles illegal tokens. eg: starting with _, | etc.
        }

    }

    ptrToken->sNextToken = "";
    ptrToken->eTokenType = UNDEFINED;

    return ptrToken;
}

bool Scanner::isoperator(int c)
{
    if (c=='+' || c=='-' || c=='*' || c=='<' || c=='>' || c=='*' || c=='&' || c=='.'
    || c=='@' || c=='/' || c==':' || c=='=' || c=='~' || c=='|' || c=='$' || c=='!'
    || c=='#' || c=='%' || c=='^' || c=='_' || c=='[' || c==']' || c=='{' || c=='}'
    || c=='"' || c=='`' || c=='?' )
        return true;
    else
        return false;

}

bool Scanner::ispuncuation(int c)
{


    if (c=='(' || c==')' || c==';' || c==',')
        return true;
    else
        return false;
}
