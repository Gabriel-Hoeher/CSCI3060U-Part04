/**
 * This is class is intended to represent transactions 
 * that do not have any additional misc information
 * Used for withdrawal, deposit, create, delete, disable
 * Also used in the Transfer class for the transfer transaction
 * Inherits from Transaction
 */

#include "Transaction.h"

class Basic: public Transaction {
    public:
        //Constructor
        Basic(char c, string aName, int aNum, float a);
        //Format transaction data for the bank transaction file
        string generateFileEntry();
};