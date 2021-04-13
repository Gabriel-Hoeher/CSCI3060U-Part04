/**
 * This class represents the data associated with a bank account 
 */

#ifndef ACCOUNT
#define ACCOUNT

#include <string>

using std::string;

class Account {
private:
        float balance;
        string owner;
        int accountNumber;
        bool isActive;
        bool isStudentPlan;
public:
        //Constructors
        Account();
        Account(float balance, string owner, int accountNumber, bool isActive, bool isStudentPlan);

        //Getters & setters
        void setBalance(float newBalance);
        void setAccountNumber(int newAccountNumber);
        void setIsActive(bool newIsActive);
        void setIsStudentPlan(bool newIsStudentPlan);
        string getOwner();
        int getAccountNum();
        float getBalance();
};

#endif