import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Read {
  public String readFile(String file){
    // putting transaction file into a list
    BufferedReader bufReader = new BufferedReader(new FileReader(file));
    ArrayList<String> listOflines = new ArrayList<>();
  
    String line = bufReader.readLine();
    while (line != null) {
      listOflines.add(line);
      line = bufReader.readLine();
    }
  
    bufReader.close();
    
    return listOflines;
  }
}