import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class readFile {
    // putting transaction file into a list
    
    BufferedReader bufReader = new BufferedReader(new FileReader("merged_bank_account_transactions.txt"));
    ArrayList<String> listOfTransactions = new ArrayList<>();

    String line = bufReader.readLine();

    while (line != null) {
        listOfTransactions.add(line);
        line = bufReader.readLine();
    }

    bufReader.close();

    return listOfTransactions;
}
