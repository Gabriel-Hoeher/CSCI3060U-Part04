import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/*
* Reads in the Master Bank Accounts File and the Merged Bank Account Transaction File
* Stores the accounts as a HashMap with the accountNumber being the key
* Stores the transactions in an array list
*/
public class Read {
  public BankAccount[] readMaster(String masterBankAccounts) {

      HashMap<String, BankAccount> accountList = new ArrayList<String, BankAccount>();
      ArrayList<Transaction> transactionList = new ArrayList<Transaction>();

      try {
          BufferedReader bufReader = new BufferedReader(masterBankAccounts);
          String line = bufReader.readLine();

          while (line != null) {
              String line = fileReader.nextLine();

              // split the lines with substring and can set the variables for BankAccount
              BankAccount bankaccount = new BankAccount(line);

              if (bankaccount.accountNumber != null) {
                  // insert into hashmap with account number as the key
                  accountList.put(bankaccount.accountNumber, bankaccount);
              }
              line = bufReader.readLine();

          }
          fileReader.close();
      } catch (Exception error) {
          // error 
      }
      BankAccount[] accounts = new BankAccount[accountList.size()];
      for (int i = 0; i<accountList.size();i++) {
          accounts[i] = accountlist.get(i)[1];
      }
      return accounts;
  }
  
  public String readFile(BankAccount[] accounts, String transactionFile) {
    try {
        BufferedReader bufReader = new BufferedReader(transactionFile);
        String line = bufReader.readLine();
        
        while (line != null) {
            String line = fileReader.nextLine();
            Transaction currentTransaction = new Transaction();
            
            // append to transactionlist
            // run as long as nameType != "00"
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