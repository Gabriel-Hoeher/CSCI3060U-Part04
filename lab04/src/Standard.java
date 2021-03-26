public class Standard extends Transaction{
  void withdraw(float value){
    currentAccount.balance = currentAccount.balance - value;

  }
  
  void transfer(float value, BankAccount transfer){
    // move money from one to another
    currentAccount.balance = currentAccount.balance - value;
    transfer.balance = transfer.balance + value;
  }
  
  void paybill(float value){
    // Should this work the same as withdraw?
    currentAccount.balance = currentAccount.balance - value;

  }
  
  void deposit(float value){
    // Add money
    currentAccount.balance = currentAccount.balance + value;
  }
  
}