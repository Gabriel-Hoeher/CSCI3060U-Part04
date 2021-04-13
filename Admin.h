/**
 * This class runs an admin session
 * Inherits from the Standard and BankUser classes
 */

#ifndef ADMIN
#define ADMIN

#include "Standard.h"
#include "Account.h"

class Admin : public Standard {
public:
        //Constructors
        Admin();
        Admin(int ac, char** av);
        //Runs an admin session
        void runSession();
        //Withdraw money from an account
        void withdrawalA();
        //Deposit money into an account
        void depositA();
        //Transfers money from one account to another
        void transferA();
        //Pays a company
        void paybillA();
        //Creates a new account
        void create();
        //Deletes a specified account
        void deletes();
        //Disables a specified account
        void disable();
        //Changes the payment plan of a specified account
        void changePlan();
};

#endif