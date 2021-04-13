/**
 * Abstract class providing a framework for user sessions
 * Parent class of Standard and Admin
 */

#ifndef BANK_USER
#define BANK_USER

#include <string>
#include "Bank.h"
#include "Account.h"
#include "Transaction.h"

using std::string;

class BankUser {
protected:
        Bank bank;
        Account account;
        vector<string> transactions;
        char** args;
public:
        //Constructor
        BankUser();
        BankUser(int ac, char** av);
        //Logs user into an account
        void login();
        //Runs a session
        virtual void runSession() = 0;
        //Logs user out of the system
        void logout();
};

#endif 