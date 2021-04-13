#include "Transaction.h"

using namespace std;

//Constructor
Transaction :: Transaction(char c, string aName, int aNum, float a) {
    this->code = c;
    this->accountName = aName;
    this->accountNum = aNum;
    this->amount = a;
}

/**
 * Formats the basic info of a transaction for the bank account transaction file
 * Does not construct the additional info (MM) part of the fixd length string,
 * additional function required to construct a full string
 */
string Transaction :: formatInfo() {
    string entry;
    string temp;
    //Format transaction num/code
    entry = entry + "0" + code;
    //Format account holder name
    entry = entry + " " + accountName;
    for(int i = 0; i < 20-accountName.length(); i++) {
        entry = entry + " ";
    }
    //Format account number
    temp = to_string(accountNum);
    entry = entry + " ";
    for(int i = 0; i < 5-temp.length(); i++) {
        entry = entry + "0";
    }
    entry = entry + temp;

    //Format amount
    temp = to_string(amount);
    for(int i = 0; i < 4; i++) { //Remove trailing 0s
        temp.pop_back();
    }
    entry = entry + " ";
    for(int i = 0; i < 8-temp.length(); i++) {
        entry = entry + "0";
    }
    entry = entry + temp;

    return entry;
}