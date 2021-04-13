#include <fstream>
#include <iostream>
#include "Bank.h"

using namespace std;

/**Constructor
 * Reads current_accounts.txt file
 * Builds accounts vector with parsed the data
 */
Bank :: Bank() {
    //Read the the current bank accounts file to build a vector of accounts
    ifstream currAccFile;
    currAccFile.open("current_accounts.txt");
    string line;
    while(getline(currAccFile,line)) {
        //Extract individual fields
        string accountNumS = line.substr(0,5);
        int accountNum = stoi(accountNumS);

        string name = line.substr(6,20);
        for(int i = name.length()-1; i >= 0; i--) {
            if(name[i] != ' ') {
                name = name.substr(0,i+1);
                break;
            }
        }

        char isActiveC = line[27];
        bool isActive = (isActiveC == 'A');

        string balanceS = line.substr(29,8);
        float balance = stof(balanceS); 

        //Build Account object
        Account temp = Account(balance,name,accountNum,isActive,false);
        accounts.push_back(temp);
    }
    currAccFile.close();
}

//Verifies that an account with the specified name, number exists in the system
bool Bank :: verifyAccount(std::string name, int accountNum) {
    for(auto i: accounts) {
        if(name == i.getOwner() && accountNum == i.getAccountNum()) {
            return true;
        }
    }
    return false;
}

//Determines the owner of the account with a given account number
string Bank :: determineOwner(int accountNum) {
    for(auto i: accounts) {
        if(accountNum == i.getAccountNum()) {
            return i.getOwner();
        }
    }
    return "";
}

//Returns the account owned by the specified name
Account Bank :: retrieve(string name) {
    Account a;
    for(auto i: accounts) {
        if(name == i.getOwner()) {
            a = i;
            return a;

        }
    }
    return a;
}

//Returns the account with the specified number owned by the specified name
Account Bank :: retrieve(string name, int accountNum) {
    Account a;
    for(auto i: accounts) {
        if(name == i.getOwner() && accountNum == i.getAccountNum()) {
            a = i;
            return a;

        }
    }
    return a;
}

//Removes a specified account from the accounts vector
void Bank :: removeAccount(string name, int accountNum) {
    for(int i = 0; i < accounts.size(); i++) {
        if(name == accounts.at(i).getOwner() && 
           accountNum == accounts.at(i).getAccountNum()) {
            accounts.erase(accounts.begin()+i);
        }
    }
}

//Disables a specified account in the accounts vector
void Bank :: disableAccount(string name, int accountNum) {
    for(auto i: accounts) {
        if(name == i.getOwner() && accountNum == i.getAccountNum()) {
            i.setIsActive(false);
        }
    }
}