#include "Basic.h"

using namespace std;

//Constructor
Basic :: Basic(char c, string aName, int aNum, float a)
:Transaction(c, aName, aNum, a) {}

/**
 * Creates fixed length string for the bank transactions file
 * Leaves additional info field empty
 */ 
string Basic :: generateFileEntry() {
    //Append spaces
    return formatInfo() + "   ";
}