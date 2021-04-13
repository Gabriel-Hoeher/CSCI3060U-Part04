#include "Transfer.h"
#include "Basic.h"

using namespace std;

//Constructor
Transfer :: Transfer(string aName, int aNum, float a,string tName, int tNum)
: Transaction('2', aName, aNum, a) {
    accountToName = tName;
    accountToNum = tNum;
}

/**
 * Constructs 2 fixed length strings for the bank_account_transaction file
 * A transfer requires 2 lines in the bank transactions file
 */
string Transfer :: generateFileEntry() {
    string entry;
    //Format transaction info for sending acccount
    entry = entry + formatInfo() + " SE" + "\n"; //SE for "sending"

    //Format transaction info for receiving account
    Basic receiver = Basic('2',accountToName, accountToNum, this->amount);
    entry = entry + receiver.formatInfo() + " RE"; //RE for "receiving"

    return entry;
}