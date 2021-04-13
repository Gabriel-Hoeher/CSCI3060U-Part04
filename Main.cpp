/**
 * Banking System Front End
 * 
 * The Front End reads in a file of bank accounts that contains information on each
 * account including balance and account owner. The Front End (1), processes a
 * stream of bank account transactions one at a time (2), and writes out a file of
 * banking account transactions at the end of the session (3).
 * 
 * Input: current_accounts.txt:
 * 
 * Output: bank_account_transaction.txt
 * 
 * Program is meant to be run from the command line.
 * Compile using make and run a.out
 */

#include <iostream>
#include <string>
#include "Bank.h"
#include "BankUser.h"
#include "Standard.h"
#include "Admin.h"

using namespace std;

int main(void) {
    //Continuously run the front end (implement a way to exit the sytem later)
    while(true) {
        //Prompt session type
        string type;
        cout << "Welcome to the bank system" << endl << "Choose a session type" 
            << endl << "(Enter 0 for Admin | Enter 1 for Standard)" << endl;
        getline(cin, type);

        //Log in
        BankUser* session;
        if(stoi(type) == 0) {
            session = new Admin();
        }
        else {
            session = new Standard();
        }
        session->login();
        session->runSession();
    }
    return 0;
}