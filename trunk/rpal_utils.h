#ifndef RPAL_UTILS_H_INCLUDED
#define RPAL_UTILS_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

class Utils
{

    public:

        static void writeExceptionToLog(string sErrorDescription);
        static void writeExceptionToLog(string sLocation, string sErrorDescription);
        static void writeExceptionToLog(string sLogFileName, string sLocation, string sErrorDescription);
};

#endif // RPAL_UTILS_H_INCLUDED
