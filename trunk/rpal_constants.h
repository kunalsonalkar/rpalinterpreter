#ifndef RPAL_CONSTANTS_H_INCLUDED
#define RPAL_CONSTANTS_H_INCLUDED
using namespace std;

enum token_types{
   IDENTIFIER,
   INTEGER,
   STRING,
   OPERATOR,
   PUNCTUATION,
   UNDEFINED,
   END_OF_FILE
};

const string LOGFILE   = "ParserErrLog.txt";
const string TOKEN_LET      = "let";
const string TOKEN_IN       = "in";
const string TOKEN_FN       = "fn";


#endif // RPAL_CONSTANTS_H_INCLUDED
