import java.util.HashMap;

public class Transaction {
    String nameType;
    float amount;
    long accountNumber;
    int transactionNum;
    String misc;
    BankAccount currentAccount;
    
    HashMap<String, BankAccount> initialize(String currentTransaction, HashMap<String,BankAccount> accountList) {
        
        // CC_AAAAAAAAAAAAAAAAAAAA_NNNNN_PPPPPPPP_MM
        // using subString to split the line into its corresponding variables
        nameType = currentTransaction.substring(0, 2);
        String accountName = currentTransaction.substring(3,23);
        accountNumber = Long.parseLong(currentTransaction.substring(24, 29));
        amount = Float.parseFloat(currentTransaction.substring(30,38));
        misc = currentTransaction.substring(39, 40);
      
        // have to initialize a new Account if the nameType is 05
        if (nameType == "05") {
            // Make new account and add to the accountList
            // Only need 2 variables accountName and accountNumber
            // currentAccount = new BankAccount(x,y)
            accountList.put(accountName, currentAccount);
        }
        
        //Getting the accountNumber of the current account
        currentAccount = accountList.get(accountNumber); 

        return accountList;
    }
}
