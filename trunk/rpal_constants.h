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
   KEYWORD,
   END_OF_FILE
};

const string LOGFILE            = "ParserErrLog.txt";
const string TOKEN_LET          = "let";
const string TOKEN_IN           = "in";
const string TOKEN_FN           = "fn";
const string TOKEN_OPEN_PARANTHESIS  = "(";
const string TOKEN_CLOSE_PARANTHESIS  = ")";
const string TOKEN_LAMBDA       = "lambda";
const string TOKEN_WHERE        = "where";
const string TOKEN_WITHIN       = "within";
const string TOKEN_AND          = "and";
const string TOKEN_REC          = "rec";
const string TOKEN_COMMA        = ",";
const string TOKEN_EQUAL        = "=";
const string TOKEN_FN_FORM      = "function_form";

#endif // RPAL_CONSTANTS_H_INCLUDED
