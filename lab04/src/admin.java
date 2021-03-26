import java.io.FilerWriter;
import java.io.IOException;

public class Admin extends Transaction{
  void create(){

    currentAccount.isActive = true;
    currentAccount.totalNumOfTransaction++;
  }
  
  void delete(){
    // transactionNum -1 ? 
    // not output anything?

  }
  
  void disable(){
    currentAccount.isActive = false;
    currentAccount.totalNumOfTransaction++;
  }
  
  void changePlan(){
    // i dont know what variables to look at to change plans
  }
  
}