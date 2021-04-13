/**
 * This class runs a standard session
 * Inherits from the BankUser classes
 */

#ifndef STANDARD
#define STANDARD

#include "BankUser.h"

class Standard: public BankUser {
protected:
        float totalAmountWithrawn;
        float totalAmountTransfered;
        string companies[3];
        int numCompanies;
        float totalBillsPaid[3];
public:
        //Constructors
        Standard();
        Standard(int ac, char** av);
        //Run a standard session
        void runSession();
        //Withdraw money from account
        void withdrawal(int n);
        //Deposit money into account
        void deposit(int n);
        //Transfer money from one acccount to another
        void transfer(int n);
        //Pay a company
        void paybill(int n);
};

#endif