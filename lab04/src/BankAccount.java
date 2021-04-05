/*
* This is the BankAccount class that defines
* all the variables used in subclasses that
* hold pertinent information about the account
*/
public class BankAccount {
    protected String accountName;
    protected long accountNumber;
    protected boolean isActive;
    protected int totalNumOfTransaction;
    protected float currentBalance;

    public BankAccount(String accountString){
        accountNumber = Long.parseLong(accountString.substring(0,4));
        accountName = accountString.substring(6,25);
        isActive = (accountString.substring(27,27) == "A");
        currentBalance = Float.parseFloat(accountString.substring(29,36));
        totalNumOfTransaction = Integer.parseInt(accountString.substring(28,41));
    }

    BankAccount(String accountName, long accountNumber, float currentBalance) {
        this.accountName = accountName;
        this.accountNumber= accountNumber;
        this.currentBalance = currentBalance;
        isActive = true;
        totalNumOfTransaction = 0;
    }
}