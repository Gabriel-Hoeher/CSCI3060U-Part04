public class Standard extends Transaction{
  void withdraw(float value){
    //Remove money from account
    currentAccount.currentBalance = currentAccount.currentBalance - value;
    currentAccount.totalNumOfTransaction++;
  }
  
  void transfer(float value, BankAccount transfer){
    // move money from one to another
    currentAccount.currentBalance = currentAccount.currentBalance - value;
    transfer.currentBalance = transfer.currentBalance + value;
    currentAccount.totalNumOfTransaction++;
  }
  
  void paybill(float value){
    // Should this work the same as withdraw?
    currentAccount.currentBalance = currentAccount.currentBalance - value;
    currentAccount.totalNumOfTransaction++;
  }
  
  void deposit(float value){
    // Add money
    currentAccount.currentBalance = currentAccount.currentBalance + value;
    currentAccount.totalNumOfTransaction++;
  }
  
}