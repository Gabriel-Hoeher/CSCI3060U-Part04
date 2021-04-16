public class Main {
    //Main method
    public static void main(String[] args) {
        String[] accountStrings;
        //Instantiate Read class to read from transaction files
        Read read = new Read();
        accountStrings = read.readMaster("../../Master.txt");

        //Takes the strings create the account objects
        BankAccount[] accounts = new BankAccount[accountStrings.length];
        for(int i = 0; i< accountStrings.length; i++){
            accounts[i] = new BankAccount(accountStrings[i]);
        }

        //Reads and runs the transaction files
        read.readFile(accounts,"transactionFile");
    }
}
