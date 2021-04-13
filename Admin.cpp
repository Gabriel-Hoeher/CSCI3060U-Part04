#include <iostream>
#include <string>
#include "Admin.h"
#include "Basic.h"
#include "AdditionalInfo.h"

using namespace std;

//Constructors
Admin :: Admin() : Standard() {}
Admin :: Admin(int ac, char** av) : Standard(ac, av) {}

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
        cout << "-delete" << endl << "-disable" << endl << "-changePlan" << endl << "-create" << endl  << "-logout" << endl;
        string command = args[4];
        
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
            cout << "Error: not a valid transaction" << endl;
        }
        //Logout after processing one transaction (for testing, comment out if unecessary)
        endSession = true;
        logout();
    }
}

//Withdraw money from a specified account
void Admin :: withdrawalA() {
    string name = args[5];
    cout << "Enter account holder name: ";
    account = bank.retrieve(name);
    totalAmountWithrawn = -1; //avoid standard user limit checks
    withdrawal(6);
}

//Deposit money into a specified account
void Admin :: depositA() {
    string name = args[5];
    cout << "Enter account holder name: ";
    account = bank.retrieve(name);
    deposit(6);
}

//Transfer money from a specified account to a different account
void Admin :: transferA() {
    string name = args[5];
    cout << "Enter account holder name: ";
    account = bank.retrieve(name);
    totalAmountTransfered = -1; //avoid standard user limit checks
    transfer(6);
}

//Pay a bill using a specified account
void Admin :: paybillA() {
    string name = args[5];
    cout << "Enter account holder name: ";
    account = bank.retrieve(name);
    for(int i = 0; i < numCompanies; i++) { //avoid standard user limit checks
        totalBillsPaid[i] = -1;
    }
    paybill(6);
}

/**
 * Create a new account
 * Only prompts the back end to make a new account
 * New account cannot be used until the back end initializes it
 */
void Admin :: create() {
    //Get new account info
    cout << "Enter the name of the new account's owner: ";
    string name = args[5];
    //Make sure input does not contain numeric chars
    for(int i = 0; i < name.size(); i++) {
        if((int)name[i] > 47 && (int)name[i] < 58) {
            cout << "Error: account name cannot contain numeric characters" << endl;
            return;
        }
    }

    cout << "Enter the account number of the new account: ";
    int num;
    string numS = args[6];
    //Make sure input does not contain non-numeric chars
    for(int i = 0; i < numS.size(); i++) {
        if((int)numS[i] < 48 || (int)numS[i] > 57) {
            cout << "Error: account number cannot contain non-numeric characters" << endl;
            return;
        }
    }
    num = stoi(numS);
    //Make sure inputted account number is available
    if(bank.determineOwner(num).size() > 0) {
        cout << "Error: that account number is already in the system" << endl;
        return;
    }

    cout << "Enter the starting balance of the new account: ";
    float balance;
    string balanceS = args[7];
    balance = stof(balanceS);
    //Make sure the initial balance is valid
    if(balance <= 0 || balance > 99999.99) {
        cout << "Error: invalid initial balance" << endl;
        return;
    }

    //Check if the account already exists in the systems
    if(!bank.verifyAccount(name, num)) {
        //Format transaction info
        Basic create = Basic('5',name,num,balance);
        transactions.push_back(create.generateFileEntry());
        cout << "Account created successfully" << endl;
    }
    else {
        cout << "Error: an account with that owner and account number already exists" << endl;
    }
}

/**
 * Delete an account
 * Removes the account from the account list so it cannot be accessed again
 */
void Admin::deletes() {
    cout << "Enter the account holder's name: ";
    string name = args[5];
    cout << "Enter the account number: ";
    int num;
    string numS = args[6];
    num = stoi(numS);

    if(bank.verifyAccount(name,num)) {
        Account a = bank.retrieve(name, num);
        //Prevent deletion of the account if it contains money
        if(a.getBalance() > 0) {
            cout << "Error: cannot delete an account with money in it" << endl;
            return;
        }

        bank.removeAccount(name,num); //stops further transactions with the account

        //Format transaction file
        Basic deleteAccount = Basic('6',name,num,0);
        transactions.push_back(deleteAccount.generateFileEntry());
        cout << "Deleted account number " << num << " owned by " << name << endl;
    }
    else {
        cout << "Error: could not find that account" << endl;
    }
}

/**Disables an account
 * No further transactions can be performed on a disabled account
 */
void Admin::disable() {
    cout << "Enter the account holder's name: ";
    string name = args[5];
    cout << "Enter the account number: ";
    int num;
    string numS = args[6];
    num = stoi(numS);

    if(bank.verifyAccount(name,num)) {
        Account a = bank.retrieve(name, num);
        if(!a.getStatus()) {
            cout << "Error: account is already disabled" << endl;
            return;
        }

        bank.disableAccount(name,num);

        //Format transaction file
        Basic dissableAccount = Basic('7',name,num,0);
        transactions.push_back(dissableAccount.generateFileEntry());
        cout << "Disabled account number " << num << " owned by " << name << endl;
    }
    else {
        cout << "Error: could not find that account" << endl;
    }
}

//Changes the payment plan of an account
void Admin :: changePlan() {
    cout << "Enter the account holder's name: ";
    string name = args[5];
    cout << "Enter the account number: ";
    int num;
    string numS = args[6];
    num = stoi(numS);
    cout << "Select plan (SP or NP): ";
    string plan = args[7];

    //Check for invalid input
    if(plan.compare("SP") || plan.compare("NP")) {
        //Format transaction info
        AdditionalInfo change = AdditionalInfo('8',name,num,0,plan);
        transactions.push_back(change.generateFileEntry());
        cout << "Changed account " << num << "'s plan to " << plan << endl;
    }
    else {
        cout << "Error: invalid payment plan entered" << endl;
    }
}