package BankSystem;

public class StudentAccount extends BankAccount{
   
    public double studentCost() {
        final float amount = 0.05f;  
        double total = 0f;

        //if this acount had a transaction
        if (totalNumOfTransaction > 0) {
            Transaction transaction = new Transaction();

            for (int i=0; i<totalNumOfTransaction; i++) total += amount;    //calculate total to withdraw

            transaction.withdraw(total);
        }
        return total;
    }
}