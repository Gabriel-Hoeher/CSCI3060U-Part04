/**
 * This class runs a standard session
 * Inherits from the BankUser classes
 */

#ifndef STANDARD
#define STANDARD

#include "BankUser.h"

class Standard : public BankUser {
public:
        //Constructor
        Standard();
        //Run a standard session
        void runSession();
        //Withdraw money from account
        void withdrawal();
        //Deposit money into account
        void deposit();
        //Transfer money from one acccount to another
        void transfer();
        //Pay a company
        void paybill();
};

#endif