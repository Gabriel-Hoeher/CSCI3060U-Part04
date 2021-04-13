/**
 * This class stores the accounts read from the current_accounts.txt file
 */

#ifndef BANK
#define BANK

#include <vector>
#include <string>
#include "Account.h"

using std::vector;
using std::string;

class Bank {
    private:
        vector<Account> accounts;
    public:
        //Constructor
        Bank();
        //Check if an account exists in the system
        bool verifyAccount(string name, int accountNum);
        //Gets the name of the owner of the account with a given account number
        string determineOwner(int accountNum);
        //Returns an account given the name of the owner
        Account retrieve(string name);
        //Returns an account given the name of the owner and the account number
        Account retrieve(string name, int accountNum);
        //Locally delete an account
        void removeAccount(string name, int accountNum);
        //Disable an account
        void disableAccount(string name, int accountNum);
};

#endif