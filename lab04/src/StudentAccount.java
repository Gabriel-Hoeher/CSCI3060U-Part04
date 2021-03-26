import java.util.HashMap;

public class StudentAccount extends BankAccount{

    public double studentCost() {
        final float amount = 0.05f;  
        float total = 0f;

        //if this acount had a transaction
        if (totalNumOfTransaction > 0) {
            Standard transaction = new Standard();
            HashMap<String, BankAccount> acc = new HashMap<>();

            //initialize transaction
            acc.put(accountName, this);
            transaction.initialize(accountName, acc);

            for (int i=0; i<totalNumOfTransaction; i++) total += amount;    //calculate total to withdraw

            if(currentBalance >= total) transaction.withdraw(total);        //if balance wont be negative
        }
        return total;
    }
}