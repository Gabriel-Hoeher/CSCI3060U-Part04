public class Main {
    BankAccount[] accounts;
    //Main method
    public static void main(String[] args) {
        //Instantiate Read class to read from transaction files
        Read read = new Read();
        accounts = read.readMaster("Master.txt");
        read.readfile("transactionFile");
    }
}
