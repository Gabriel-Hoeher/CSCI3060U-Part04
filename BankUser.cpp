#include <iostream>
#include <fstream>
#include "BankUser.h"

using namespace std;

//Constructors
BankUser :: BankUser() {
    bank = Bank();
}
BankUser :: BankUser(int ac, char** av) {
    bank = Bank();
    args = new char*[ac];
    for(int i = 0; i < ac; i++) {
        args[i] = av[i];
    }
}

/**
 * Logs the user into an account 
 * The user can perform transactions with the account they've logged into
 */
void BankUser :: login() {
    bool successful = false;
    string name, accountNum;
    name = args[2];
    accountNum = args[3];
    while(successful == false) {
        cout << "Name: ";
        cout << "Account number: ";

        //Verify credentials
        if(!bank.verifyAccount(name, stoi(accountNum))) {
            cout << "Invalid credentials" << endl;
        }
        else {
            successful = true;
            account = bank.retrieve(name, stoi(accountNum));
        }
    }
}

/**
 * Logs user out of the system, ending a session
 * Writes the list of all the transactions performed in the
 * bank_account_transaction.txt file
 */ 
void BankUser::logout() {
    //Write to the bank account transaction file
    ofstream write;
    write.open("bank_account_transaction.txt");
    for(int i = 0; i < transactions.size(); i++) {
        string line = transactions[i];
        write << line << endl;
    }
    write.close();

    cout << "Thank you for using our service!" << endl;
}