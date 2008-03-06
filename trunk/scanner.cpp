#include "scanner.h"

scanner::scanner(char* name)
{

    filestream.open(name, ios::in|ios::ate);

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

scanner::~scanner()
{

    delete fileptr;

}

bool scanner::isEOF()
{
    return (index < filesize) ? false : true;
}

string scanner::getnexttoken()
{
    string currtoken = "";

    if (index >= filesize)
    {
        return "";
    }

    while (index < filesize)
    {
        char currchar = fileptr[index];


        /*
            Check for identifier tokens
            Identifier -> Letter (Letter | Digit | ’_’)* => ’<IDENTIFIER>’;
            Notes: ge, le which are keywords will be detected as an ID in the scanner. Parser should work on it
        */

        if (isalpha(currchar))
        {
            do
            {
                currtoken += fileptr[index];
                index++;
            } while ( !isEOF() && (fileptr[index] == '_') || isalpha(fileptr[index]) || isdigit(fileptr[index]) );

            return currtoken;
        }

        /*
            Check for digits
            Integer ->Digit+ =>’<INTEGER>’;
        */

        if (isdigit(currchar))
        {
            do
            {
                currtoken += fileptr[index];
                index++;
            } while ( !isEOF() && isdigit(fileptr[index]) );

            return currtoken;
        }


        /*
            Extract operator tokens
            Operator -> Operator_symbol+ => ’<OPERATOR>’;
        */

        if (isoperator(currchar))
        {
            do
            {
                currtoken += fileptr[index];
                index++;
            } while ( !isEOF() && isoperator(fileptr[index]) );

            return currtoken;
        }

        /*
            Extract string literals
        */
        if (currchar == '\'')
        {
            index++;
            do
            {
                currtoken += fileptr[index];
            } while( !isEOF() && (currchar = fileptr[index++]) != '\'');

            currtoken += currchar; //suspect : what about the last char in the string? and why is currchar assigned to currtoken

            return currtoken;
        }

        /*
            Bypass spaces and tabs
        */

        if( isspace(currchar) || currchar == '\t' || currchar == '\n' )
        {
            index++;
        }

        /*
            If a comment (\\) is found, skip the characters
            until a end of line character is encountered.
        */

        if(currchar=='\\')
        {
            if(fileptr[index+1] == '\\')
            {
                while( (fileptr[++index] != '\n') );
            }
            else
            {
                currtoken += currchar;
                return currtoken;
            }
        }

        /*
            Extract punctuations
        */

        if ( ispuncuation(currchar) )
        {
            currtoken += currchar;
            index++;
            return currtoken;
        }

    }

    return "";
}

bool scanner::isoperator(int c)
{
    if (c=='+' || c=='-' || c=='*' || c=='<' || c=='>' || c=='*' || c=='&' || c=='.'
    || c=='@' || c=='/' || c==':' || c=='=' || c=='~' || c=='|' || c=='$' || c=='!'
    || c=='#' || c=='%' || c=='^' || c=='_' || c=='[' || c==']' || c=='{' || c=='}'
    || c=='"' || c=='`' || c=='?' )
        return true;
    else
        return false;

}

bool scanner::ispuncuation(int c)
{


    if (c=='(' || c==')' || c==';' || c==',')
        return true;
    else
        return false;
}
