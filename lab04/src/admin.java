import java.io.FilerWriter;
import java.io.IOException;

public class Admin extends Transaction{
  void create(){
    currentAccount.isActive = true;
  }
  
  void delete(){
    // transactionNum -1 ? 
    // not output anything?

  }
  
  void disable(){
    currentAccount.isActive = false;

  }
  
  void changePlan(){
    // i dont know what variables to look at to change plans
  }
  
}