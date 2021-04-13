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

int main(int argc, char* argv[]) {
    //Prompt session type
    string type = argv[1];
    cout << "Welcome to the bank system" << endl << "Choose a session type" 
        << endl << "(Enter 0 for Admin | Enter 1 for Standard)" << endl;

    //Log in
    try { //handle invalid inputs for the entire program
        BankUser* session;
        if(stoi(type) == 0) {
            session = new Admin(argc, argv);
        }
        else {
            session = new Standard(argc, argv);
        }
        session->login();
        session->runSession();
    } catch (const std::exception& ex) {
        cout << "Invalid input" << endl;
    }
    return 0;
}