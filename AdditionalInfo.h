/**
 * This class represents the transactions that require addtional info
 * Transactions that require addtional info: changePlan, paybill 
 */

#ifndef ADDITIONAL
#define ADDITIONAL
 
#include "Transaction.h"

class AdditionalInfo: public Transaction {
    private:
        string addition;

    public:
        //Constructor
        AdditionalInfo(char c, string aName, int aNum, float amount, string addition);
        //Format transaction data for the bank transaction file
        string generateFileEntry();
};

#endif