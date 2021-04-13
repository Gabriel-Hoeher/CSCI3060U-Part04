#include <string>
#include <iostream>
#include "Standard.h"
#include "Transaction.h"
#include "Basic.h"
#include "AdditionalInfo.h"
#include "Transfer.h"

using namespace std;

//Constructor
Standard :: Standard() : BankUser(){}

/**
 * Runs a standard session
 * Asks for user inputs and runs transactions until the user logs out
 */
void Standard :: runSession() {
    cout << "Logged in to standard session" << endl;

    //Loop until lockout
    bool endSession = false;
    while(endSession == false) {
        //Prompt the user to select a transaction
        cout << "Select a transaction" << endl;
        cout << "-withdrawal" << endl << "-deposit" << endl << "-transfer" << endl << "-paybill" <<endl;
        cout << "-logout" << endl;
        string command;
        getline(cin,command);

        //Perform selected transaction
        if(command.compare("logout") == 0) {
            endSession = true;
            logout();
        }
        else if(command.compare("withdrawal") == 0) {
           withdrawal();
        }
        else if(command.compare("deposit") == 0) {
            deposit();
        }
        else if(command.compare("transfer") == 0) {
            transfer();
        }
        else if(command.compare("paybill") == 0) {
            paybill();
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}

//Allows the user to withdraw money from the account they're logged into
void Standard :: withdrawal() {

    cout << "Please enter the amount of money you would like to withdraw today!" << endl;
    string amountS;
    getline(cin,amountS);
    float amount = stof(amountS);
    
    if (account.getBalance() - amount < 0) {
        cout << "Not enough funds for the transations!" << endl;
    }else {
        account.setBalance(account.getBalance() - amount);
        cout << "Remaining Balance: " << account.getBalance() << endl;

        //Format transaction info 
        Basic withdrawal = Basic('1',account.getOwner(),account.getAccountNum(),amount);
        transactions.push_back(withdrawal.generateFileEntry());
    }

}

/**
 * Allows the user to deposit money into the account they're logged into 
 */
void Standard::deposit() {
    float amount = 0;
    while (amount <= 0) {
        cout << "Please enter the amount of money you would like to deposit today!" << endl;
        string amountS;
        getline(cin,amountS);
        amount = stof(amountS);

        account.setBalance(account.getBalance()+amount);
        cout << "New balance: " << account.getBalance() << endl;

        //Format transaction info
        Basic deposit = Basic('4',account.getOwner(),account.getAccountNum(),amount);
        transactions.push_back(deposit.generateFileEntry());
    }
}

/**
* Allows the user to transfer funds from the account they're logged into to a specified account
*/
void Standard::transfer() {
    float amount = 0;
    int receiverNum;
    string command;
    cout << "Enter the account number of the account that will be receiving this transfer:" << endl;
    getline(cin, command);
    receiverNum = stoi(command); //does not verify if receiving account exists, add later
    cout << "Please enter the amount of money you would like to transfer today!" << endl;
    getline(cin,command);
    amount = stof(command);

    if (account.getBalance() >= amount) {
        account.setBalance(account.getBalance()-amount);

        //Find the account the money is being transfered to
        string receiverName = bank.determineOwner(receiverNum);

        //Format transaction info
        Transfer obj = Transfer(account.getOwner(),account.getAccountNum(),amount,receiverName, receiverNum);
        transactions.push_back(obj.generateFileEntry());
        cout << "Transfer compeleted!" << endl;
    }else {
        cout << "Insufficient Funds" << endl; 
    }
}

/**
 * Allows the user to use the account they're logged into to pay a company 
 */
void Standard::paybill() {
    float amount = 0;
    string payee;
    cout << "Select a bill payee:" << endl << "-EC" << endl << "-CQ" << endl << "-FI" << endl;
    getline(cin,payee);
    cout << "Enter amount: ";
    string amountS;
    getline(cin,amountS);
    amount = stof(amountS);

    if (amount > account.getBalance()) {
        cout << "Insufficient Funds" << endl;
    }
    else {
        account.setBalance(account.getBalance()-amount);

        //Format transaction info
        AdditionalInfo payment = AdditionalInfo('3',account.getOwner(),account.getAccountNum(),amount,payee);
        transactions.push_back(payment.generateFileEntry());
        
        cout << "Sent " << amount << " to " << payee << endl;
    }
}