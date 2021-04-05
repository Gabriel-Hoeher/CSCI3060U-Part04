import java.util.HashMap;

/*
 * This is a subclass of Bank Account that will create a
 * transaction that will withdraw 0.1 dollars for every
 * transaction an account has made that day
 * */
public class RegularAccount extends BankAccount {
    RegularAccount(String accountName, long accountNumber, float currentBalance) {
        super(accountName, accountNumber, currentBalance);
    }

    /*
     * This is the method that will preform the transaction
     * returning the total amount
     * */
    public double regularCost() {
        final float amount = 0.1f;  
        float total = 0f;

        //if this account had a transaction
        if (totalNumOfTransaction > 0) {
            Standard transaction = new Standard();
            HashMap<String, BankAccount> acc = new HashMap<String, BankAccount>();

            //initialize transaction
            acc.put(accountName, this);
            transaction.initialize(accountName, acc);

            for (int i=0; i<totalNumOfTransaction; i++) total += amount;    //calculate total to withdraw

            if(currentBalance >= total) transaction.withdraw(total);
        }
        return total;
    }
}