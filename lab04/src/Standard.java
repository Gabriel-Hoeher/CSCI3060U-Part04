public class Standard extends Transaction{
  void withdraw(float value){
    //Remove money from account
    currentAccount.balance = currentAccount.balance - value;
    currentAccount.totalNumOfTransaction++;
  }
  
  void transfer(float value, BankAccount transfer){
    // move money from one to another
    currentAccount.balance = currentAccount.balance - value;
    transfer.balance = transfer.balance + value;
    currentAccount.totalNumOfTransaction++;
  }
  
  void paybill(float value){
    // Should this work the same as withdraw?
    currentAccount.balance = currentAccount.balance - value;
    currentAccount.totalNumOfTransaction++;
  }
  
  void deposit(float value){
    // Add money
    currentAccount.balance = currentAccount.balance + value;
    currentAccount.totalNumOfTransaction++;
  }
  
}