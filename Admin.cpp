#include <iostream>
#include <string>
#include "Admin.h"
#include "Basic.h"
#include "AdditionalInfo.h"

using namespace std;

Admin :: Admin() : Standard() {}

/**
 * Runs an admin session
 * Asks for user inputs and runs transactions until the user logs out
 */
void Admin :: runSession() {
    cout << "Logged in to admin session" << endl;
    bool endSession = false;

    //Loop until a logout transaction is processed
    while(endSession == false) {
        //Prompt the user to select a transaction
        cout << "Select a transaction" << endl;
        cout << "-withdrawal" << endl << "-deposit" << endl << "-transfer" << endl << "-paybill" <<endl;
        cout << "-delete" << endl << "-disable" << endl << "-changePlan" << endl << "-logout" << endl;
        string command;
        getline(cin,command);
        
        //Perform selected transaction
        if(command.compare("logout") == 0) {
            endSession = true;
            logout();
        }
        else if(command.compare("withdrawal") == 0) {
           withdrawalA();
        }
        else if(command.compare("deposit") == 0) {
            depositA();
        }
        else if(command.compare("transfer") == 0) {
            transferA();
        }
        else if(command.compare("paybill") == 0) {
            paybillA();
        }
        else if(command.compare("create") == 0) {
            create();
        }
        else if(command.compare("delete") == 0) {
            deletes();
        }
        else if(command.compare("disable") == 0) {
            disable();
        }
        else if(command.compare("changePlan") == 0) {
            changePlan();
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}

//Withdraw money from a specified account
void Admin :: withdrawalA() {
    string name;
    cout << "Enter account holder name: ";
    getline(cin, name);
    account = bank.retrieve(name);
    withdrawal();
}

//Deposit money into a specified account
void Admin :: depositA() {
    string name;
    cout << "Enter account holder name: ";
    getline(cin, name);
    account = bank.retrieve(name);
    deposit();
}

//Transfer money from a specified account to a different account
void Admin :: transferA() {
    string name;
    cout << "Enter account holder name: ";
    getline(cin, name);
    account = bank.retrieve(name);
    transfer();
}

//Pay a bill using a specified account
void Admin :: paybillA() {
    string name;
    cout << "Enter account holder name: ";
    getline(cin, name);
    account = bank.retrieve(name);
    paybill();
}

/**
 * Create a new account
 * Only prompts the back end to make a new account
 * New account cannot be used until the back end initializes it
 */
void Admin :: create() {
    //Get new account info
    cout << "Enter the name of the new account's owner: ";
    string name;
    getline(cin, name);
    cout << "Enter the account number of the new account: ";
    int num;
    string numS;
    getline(cin,numS);
    num = stoi(numS);
    cout << "Enter the starting balance of the new account: ";
    float balance;
    string balanceS;
    getline(cin,balanceS);
    balance = stof(balanceS);

    //Format transaction info
    Basic create = Basic('5',name,num,balance);
    transactions.push_back(create.generateFileEntry());
    cout << "Account created successfully" << endl;
}

/**
 * Delete an account
 * Removes the account from the account list so it cannot be accessed again
 */
void Admin::deletes() {
    cout << "Enter the account holder's name: ";
    string name;
    getline(cin, name);
    cout << "Enter the account number: ";
    int num;
    string numS;
    getline(cin,numS);
    num = stoi(numS);

    if(bank.verifyAccount(name,num)) {
        bank.removeAccount(name,num);

        //Format transaction file
        Basic deleteAccount = Basic('6',name,num,0);
        transactions.push_back(deleteAccount.generateFileEntry());
        cout << "Deleted account number " << num << " owned by " << name << endl;
    }
    else {
        cout << "Could not find that account" << endl;
    }


}

/**Disables an account
 * No further transactions can be performed on a disabled account
 */
void Admin::disable() {
    cout << "Enter the account holder's name: ";
    string name;
    getline(cin, name);
    cout << "Enter the account number: ";
    int num;
    string numS;
    getline(cin,numS);
    num = stoi(numS);

    if(bank.verifyAccount(name,num)) {
        bank.disableAccount(name,num);

        //Format transaction file
        Basic dissableAccount = Basic('7',name,num,0);
        transactions.push_back(dissableAccount.generateFileEntry());
        cout << "Disabled account number " << num << " owned by " << name << endl;
    }
    else {
        cout << "Could not find that account" << endl;
    }
}

//Changes the payment plan of an account
void Admin :: changePlan() {
    cout << "Enter the account holder's name: ";
    string name;
    getline(cin, name);
    cout << "Enter the account number: ";
    int num;
    string numS;
    getline(cin,numS);
    num = stoi(numS);
    cout << "Select plan (SP or NP): ";
    string plan;
    getline(cin, plan);

    //Format transaction info
    AdditionalInfo change = AdditionalInfo('8',name,num,0,plan);
    transactions.push_back(change.generateFileEntry());
    cout << "Changed account " << num << "'s plan to " << plan << endl;
}

