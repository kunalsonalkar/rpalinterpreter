using namespace std;

#include "rpal_utils.h"
#include "rpal_constants.h"

void Utils::writeExceptionToLog(string sErrorDescription)
{
    writeExceptionToLog(LOGFILE, " ", sErrorDescription);
}

void Utils::writeExceptionToLog(string sLocation, string sErrorDescription)
{
    writeExceptionToLog(LOGFILE, sLocation, sErrorDescription);
}

void Utils::writeExceptionToLog(string sLogFileName, string sLocation, string sErrorDescription)
{
    ofstream errfile(sLogFileName.c_str());

    if (errfile.is_open())
    {
        errfile <<sLocation<<"\t\t";
        errfile <<sErrorDescription<<"\n";
        errfile.close();
    }

}
