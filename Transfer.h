/**
 * This class represents the transfer transaction
 * Inherits from the Transaction class
 */

#ifndef TRANSFER
#define TRANSFER

#include "Transaction.h"

class Transfer: public Transaction {
    private:
        string accountToName;
        int accountToNum;
    public:
        //Constructor
        Transfer(string aName, int aNum, float a, string tName, int tNum);
        //Formats transaction data for the bank transaction file
        string generateFileEntry();
};

#endif 