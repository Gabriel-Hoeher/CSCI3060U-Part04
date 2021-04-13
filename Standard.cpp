#include <string>
#include <iostream>
#include "Standard.h"
#include "Transaction.h"
#include "Basic.h"
#include "AdditionalInfo.h"
#include "Transfer.h"

using namespace std;

//Constructors
Standard :: Standard() : BankUser() {}
Standard :: Standard(int ac, char** av) : BankUser(ac, av) {
    totalAmountTransfered, totalAmountWithrawn = 0;
    numCompanies = 3;
    companies[0] = "EC";
    companies[1] = "CQ";
    companies[2] = "FI";
    totalBillsPaid[0],totalBillsPaid[1],totalBillsPaid[2] = -1;
}

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
        string command = args[4];

        //Perform selected transaction
        if(command.compare("logout") == 0) {
            endSession = true;
            logout();
        }
        else if(command.compare("withdrawal") == 0) {
           withdrawal(5);
        }
        else if(command.compare("deposit") == 0) {
            deposit(5);
        }
        else if(command.compare("transfer") == 0) {
            transfer(5);
        }
        else if(command.compare("paybill") == 0) {
            paybill(5);
        }
        else {
            cout << "Error: not a valid transaction" << endl;
        }
        //Logout after processing one transaction (for testing, comment out if unecessary)
        endSession = true;
        logout();
    }
}

/**
 * Allows the user to withdraw money from the account they're logged into
 * n is the start index of the transaction inputs in the argv array
 */
void Standard :: withdrawal(int n) {

    cout << "Please enter the amount of money you would like to withdraw today" << endl;
    string amountS = args[n];
    float amount;
    amount = stof(amountS);
    
    if (totalAmountWithrawn >= 500 && totalAmountWithrawn > -1) {
        cout << "Error: session withdrawal cap of $500.00 has been reached" << endl;
    }
    else if(totalAmountWithrawn + amount > 500 && totalAmountWithrawn > -1) {
        cout << "Error: transaction exceeds the session withdrawal cap of $500.00" << endl;

    }
    else if (account.getBalance() - amount < 0) {
        cout << "Error: not enough funds for the transations" << endl;
    }
    else {
        account.setBalance(account.getBalance() - amount);
        cout << "Remaining Balance: " << account.getBalance() << endl;
        totalAmountWithrawn = totalAmountWithrawn + amount;

        //Format transaction info 
        Basic withdrawal = Basic('1',account.getOwner(),account.getAccountNum(),amount);
        transactions.push_back(withdrawal.generateFileEntry());
    }

}

/**
 * Allows the user to deposit money into the account they're logged into 
 * n is the start index of the transaction inputs in the argv array 
 */
void Standard::deposit(int n) {
    float amount = 0;
    cout << "Please enter the amount of money you would like to deposit today" << endl;
    string amountS = args[n];
    amount = stof(amountS);
    
    account.setBalance(account.getBalance()+amount);
    cout << "New balance: " << account.getBalance() << endl;

    //Format transaction info
    Basic deposit = Basic('4',account.getOwner(),account.getAccountNum(),amount);
    transactions.push_back(deposit.generateFileEntry());
}

/**
 * Allows the user to transfer funds from the account they're logged into to a specified account
 * n is the start index of the transaction inputs in the argv array
 */
void Standard::transfer(int n) {
    float amount = 0;
    int receiverNum;
    string command = args[n];
    cout << "Enter the account number of the account that will be receiving this transfer:" << endl;
    receiverNum = stoi(command);
    
    //Verify that an account with the inputted account number exists in the system
    if(bank.determineOwner(receiverNum).size() == 0) {
        cout << "Error: could not find an account with that account number" << endl;
        return;
    }

    cout << "Please enter the amount of money you would like to transfer today!" << endl;
    command = args[n+1];
    amount = stof(command);
    
    if (totalAmountTransfered >= 1000 && totalAmountTransfered > -1) {
        cout << "Error: session transfer cap of $1000.00 has been reached" << endl;
    }
    else if(totalAmountWithrawn + amount > 1000 && totalAmountTransfered > -1) {
        cout << "Error: transaction exceeds the session transfer cap of $1000.00" << endl;

    }
    else if (account.getBalance() >= amount) {
        account.setBalance(account.getBalance()-amount);
        totalAmountTransfered = totalAmountTransfered + amount;

        //Find the account the money is being transfered to
        string receiverName = bank.determineOwner(receiverNum);

        //Format transaction info
        Transfer obj = Transfer(account.getOwner(),account.getAccountNum(),amount,receiverName, receiverNum);
        transactions.push_back(obj.generateFileEntry());
        cout << "Transfer compeleted!" << endl;
    }
    else {
        cout << "Error: insufficient Funds" << endl; 
    }
}

/**
 * Allows the user to use the account they're logged into to pay a company 
 * n is the start index of the transaction inputs in the argv array
 */
void Standard::paybill(int n) {
    float amount = 0;
    string payee = args[n];
    cout << "Select a bill payee:" << endl;
    for(int i = 0; i < numCompanies; i++) {
        cout << "-" << companies[i] << endl;
    }
    //Make sure a valid company was entered
    int index = -1; //used to access the value for the total money paid to the company during the session
    for(int i = 0; i < numCompanies; i++) {
        if(companies[i].compare(payee) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "Error: that company doesn't exist in the system" << endl;
        return;
    }

    cout << "Enter amount: ";
    string amountS = args[n+1];
    amount = stof(amountS);

    if (totalBillsPaid[index] >= 2000 && totalBillsPaid[index] > -1) {
       cout << "Error: session paybill cap of $2000.00 has been reached" << endl;
    }
    else if(totalBillsPaid[index] + amount > 2000 && totalBillsPaid[index] > -1) {
        cout << "Error: transaction exceeds the session paybill cap of $2000.00" << endl;
    }
    else if (amount > account.getBalance()) {
        cout << "Error: insufficient Funds" << endl;
    }
    else {
        account.setBalance(account.getBalance()-amount);

        //Format transaction info
        AdditionalInfo payment = AdditionalInfo('3',account.getOwner(),account.getAccountNum(),amount,payee);
        transactions.push_back(payment.generateFileEntry());
        
        cout << "Sent " << amount << " to " << payee << endl;
    }
}