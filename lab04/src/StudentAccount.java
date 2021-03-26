import java.util.HashMap;

/*
* This is a subclass of Bank Account that will create a
* transaction that will withdraw 0.05 dollars for every
* transaction an account has made that day
* */
public class StudentAccount extends BankAccount{
    /*
    * This is the method that will preform the transaction
    * returning the total amount
    * */
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