#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

Account::Account() {
    this->balance = 0;
    this->owner = "";
    this->isActive = true;
    this->isStudentPlan = false;
    this->accountNumber = 0;
}

//constructor 
Account::Account(float aBalance,string name,int aAccountNumber, 
    bool aIsActive,bool aIsStudentPlan) : balance(aBalance),
     accountNumber(aAccountNumber), isActive(aIsActive),
     isStudentPlan(aIsStudentPlan)
 {
     this->owner = name;
 }

//set Balance
 void Account::setBalance(float newBalance)
 {
     this->balance = newBalance;
 }

//set account number
  void Account::setAccountNumber(int newAccountNumber)
 {
     this->accountNumber = newAccountNumber;
 }

//set active status 
  void Account::setIsActive(bool newIsActive)
 {
     this->isActive = newIsActive;
 }

//set student plan status
  void Account::setIsStudentPlan(bool newIsStudentPlan)
 {
     this->isStudentPlan = newIsStudentPlan;
 }

 //get account owner's name
 string Account :: getOwner()
 {
     return this->owner;
 }

 //get account number
 int Account :: getAccountNum()
 {
     return this->accountNumber;
 }

//get account balance
float Account :: getBalance() {
    return this->balance;
}

//get active status
bool Account :: getStatus() {
    return this->isActive;
}