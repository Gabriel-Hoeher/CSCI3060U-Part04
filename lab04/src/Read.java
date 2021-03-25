import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Read {
  public String readFile(String masterBankAccounts, String transactionFile){
    
    HashMap<String,BankAccount> accountList = new ArrayList<String,BankAccount>();
    ArrayList<Transaction> transactionList = new ArrayList<Transaction>();
    
    try {
        BufferedReader bufReader = new BufferedReader(masterBankAccounts);
        String line = bufReader.readLine();
    
        while (line != null) {
            String line = fileReader.nextLine();
            
            // split the lines with substring and can set the variables for BankAccount
            BankAccount bankaccount = new BankAccount(line);

            if(bankaccount.accountNumber != null){
              // insert into hashmap with account number as the key
              accountList.put(bankaccount.accountNumber, bankaccount);
            }
            line = bufReader.readLine();
    
        }
        fileReader.close();
    }
    catch (Exception error) {
        // error 
    }
    
    try {
        BufferedReader bufReader = new BufferedReader(transactionFile);
        String line = bufReader.readLine();
        
        while (line != null) {
            String line = fileReader.nextLine();
            Transaction currentTransaction = new Transaction();
            
            // append to transactionlist
            // if transactionNum is "00" break
            transaction.initialize(currentTransaction, accountList);
            if (transaction.nameType != "00") {
              transactionList.add(currentTransaction);
            }
            line = bufReader.readLine();
        }
        fileReader.close();
    }
    catch (Exception error) {
        // error
    }
    
  }
}