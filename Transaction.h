/**
 * Abstract class intended to store and format transaction data
 * Parent class of the Basic, AdditonalInfo, & Transfer classes
 */

#ifndef TRANSACTION
#define TRANSACTION
#include <string>

using std::string;

class Transaction {
    protected:
        char code;
        string accountName;
        int accountNum;
        float amount;
    public:
        //Constructor
        Transaction(char c, string aName, int aNum, float a);
        //Formats basic info required for the bank_account_transaction file
        string formatInfo();
        //Completes the fixed length string outputted to the bank_account_transaction file
        virtual string generateFileEntry() = 0;
};

#endif