public class RegularAccount extends BankAccount {

    public double regularCost() {
        final float amount = 0.1f;  
        double total = 0f;

        //if this account had a transaction
        if (totalNumOfTransaction > 0) {
            Transaction transaction = new Transaction();                /*Error until Transaction is added*/

            for (int i=0; i<totalNumOfTransaction; i++) total += amount;    //calculate total to withdraw

            transaction.withdraw(total);
        }
        return total;
    }
}