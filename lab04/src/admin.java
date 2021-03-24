import java.io.FilerWriter;
import java.io.IOException;

public class Admin extends Transaction{
  public void create(){
    // read file
    FileWriter create = new FilerWriter("master_accounts.txt");
    // create.write("NNNNN_AAAAAAAAAAAAAAAAAAAA_S_PPPPPPPP_TTTT")
    if(Transaction.amount < 0){
      //Error
    }
    else{ // probably doesn't work but should be the basis of generateFile() if we choose to implement it
      create.write(String.valueOf(Transaction.accountNumber) + " " + BankAccount.accountName + " " + "A " + String.valueOf(Transaction.amount)
                          + " " + String.valueOf(BankAccount.totalNumOfTransaction));
    }
    create.close();

  }
  
  public void delete(){
    
    // dont write anything?
    
  }
  
  public void disable(){
    
    FileWriter disable = new FilerWriter("master_accounts.txt");
    
    if(Transaction.amount < 0){
      //error
    }
    else{
      if(BankAccount.isActive){
        disable.write(String.valueOf(Transaction.accountNumber) + " " + BankAccount.accountName + " " + "A "  + String.valueOf(Transaction.amount)
                            + " " + String.valueOf(BankAccount.totalNumOfTransaction));
      }
      else{
        disable.write(String.valueOf(Transaction.accountNumber) + " " + BankAccount.accountName + " " + "D "  + String.valueOf(Transaction.amount)
                            + " " + String.valueOf(BankAccount.totalNumOfTransaction));
      }
      
    }
    
    disable.close();
  }
  
  public void changePlan(){
    
    FileWriter changePlan = new FilerWriter("master_accounts.txt");
    
    changePlan.write(String.valueOf(Transaction.accountNumber) + " " + BankAccount.accountName + " " + "A " + String.valueOf(Transaction.amount)
                        + " " + String.valueOf(BankAccount.totalNumOfTransaction));
    changePlan.close();
  }
  
}