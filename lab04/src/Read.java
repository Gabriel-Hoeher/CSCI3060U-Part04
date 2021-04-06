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
    //Stores tge account number and actual value of the account
    private class AccountPair
    {
        String accountNumber;
        BankAccount account;
        public AccountPair(String accountNumber, BankAccount account)
        {
            this.accountNumber = accountNumber;
            this.account = account;
        }
    }

    public String[] readMaster(String masterBankAccounts) {

      ArrayList<AccountPair> accountList = new ArrayList<AccountPair>();
      ArrayList<String> accountStringList = new ArrayList<String>();

      try {
          BufferedReader bufReader = new BufferedReader(new FileReader(masterBankAccounts));
          String line;

          while ((line = bufReader.readLine()) != null) {

              // split the lines with substring and can set the variables for BankAccount
              BankAccount bankaccount = new BankAccount(line);

              // insert into hashmap with account number as the key (no longer necessary)
              accountList.add(new AccountPair(""+bankaccount.accountNumber, bankaccount));
              accountStringList.add(line);

          }
          bufReader.close();
      } catch (Exception error) {
          // error 
      }
      //Translates the Account Pairs to a list of accounts (no longer necessary)
      BankAccount[] accounts = new BankAccount[accountList.size()];
      for (int i = 0; i<accountList.size();i++) {
          accounts[i] = accountList.get(i).account;
      }

      //Translates the list of strings into an array of strings to make testing easier
      String[] returnArray = new String[accountStringList.size()];
      for (int i = 0; i<accountStringList.size();i++) {
          returnArray[i] = accountStringList.get(i);
      }
      return returnArray;
  }
  
  public void readFile(BankAccount[] accounts, String transactionFile) {
      ArrayList<Transaction> transactionList = new ArrayList<Transaction>();
      try {
          BufferedReader bufReader = new BufferedReader(new FileReader(transactionFile));
          String line;

          while ((line = bufReader.readLine()) != null) {
              Transaction currentTransaction = new Transaction();

              // append to transactionlist
              // run as long as nameType != "00"
              if (currentTransaction.nameType != "00") {
                  transactionList.add(currentTransaction);
              }
          }
          bufReader.close();
      } catch (Exception error) {
          // error
      }
  }
}