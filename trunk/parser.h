#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "stack.h"
#include "scanner.h"

using namespace std;
class Parser{

  private:
        Stack* oStack;
        Scanner* oScanner;

  public:
        //constructor
        Parser();
        Parser(string sFileName);

        //destructor
        ~Parser();

        //Methods

        //#Expressions##############################
        bool proc_E();
        bool proc_Ew();

        //#Tuple Expressions##############################
        bool proc_T();
        bool proc_Ta();
        bool proc_Tc();

        //#Boolean Expressions##############################
        bool proc_B();
        bool proc_Bt();
        bool proc_Bs();
        bool proc_Bp();

        //#Arithmetic Expressions##############################
        bool proc_A();
        bool proc_At();
        bool proc_Af();
        bool proc_Ap();

        //#Rators And Rands##############################
        bool proc_R();
        bool proc_Rn();

        //#Definitions##############################
        bool proc_D();
        bool proc_Da();
        bool proc_Dr();
        bool proc_Db();

        //#Variables##############################
        bool proc_Vb();
        bool proc_Vl();


};

#endif // PARSER_H_INCLUDED
