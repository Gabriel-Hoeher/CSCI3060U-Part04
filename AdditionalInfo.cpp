#include "AdditionalInfo.h"

using namespace std;

//Constructor
AdditionalInfo :: AdditionalInfo(char c, string aName, int aNum, float amount, string addition) 
: Transaction(c,aName,aNum,amount) {
    this->addition = addition;
}

//Generates the string outputted to the bank_account_transaction.txt file
string AdditionalInfo :: generateFileEntry() {
    string entry = formatInfo() + " " + addition;
    return entry;
}