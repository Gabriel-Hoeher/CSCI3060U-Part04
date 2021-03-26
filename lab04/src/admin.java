import java.io.FilerWriter;
import java.io.IOException;

public class Admin extends Transaction{
  void create(){
    // set the current account's status to true 
    // add 1 to the totalNumOfTransaction
    currentAccount.isActive = true;
    currentAccount.totalNumOfTransaction++;
  }
  
  void delete(){
    // transactionNum -1 ? 
    // set current account's status to false
    currentAccount.isActive = false;
  }
  
  void disable(){
    // set the current account's status to false 
    // add 1 to the totalNumOfTransaction
    currentAccount.isActive = false;
    currentAccount.totalNumOfTransaction++;
  }
  
  // changePlan removed because none of the things in the transaction file can tell as anything about the plan
  
}