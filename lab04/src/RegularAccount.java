import java.util.HashMap;

public class RegularAccount extends BankAccount {

    public double regularCost() {
        final float amount = 0.1f;  
        float total = 0f;

        //if this account had a transaction
        if (totalNumOfTransaction > 0) {
            Standard transaction = new Standard();
            HashMap<String, BankAccount> acc = new HashMap<>();

            //initialize transaction
            acc.put(accountName, this);
            transaction.initialize(accountName, acc);

            for (int i=0; i<totalNumOfTransaction; i++) total += amount;    //calculate total to withdraw

            if(currentBalance >= total) transaction.withdraw(total);
        }
        return total;
    }
}