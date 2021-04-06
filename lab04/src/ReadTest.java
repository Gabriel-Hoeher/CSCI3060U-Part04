import org.junit.Test;
import org.junit.jupiter.api.Assertions;

class ReadTest {
  
  /* Tests for loop coverage */
  /* Tests according to while box testing II lecture */
  
  // Tests if loop executes body 0 times for readMaster
  @Test
  void ReadMasterLoop1(){
    String[] accounts;
    Read read = new Read();
    // empty txt file
    accounts = read.readMaster("empty.txt");
    Assertions.assertEquals(new String[]{}, accounts);
  }
  
  void ReadMasterLoop2(){
    String[] accounts;
    Read read = new Read();
    // empty txt file
    accounts = read.readMaster("test1.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000"}, accounts);
  }
  
  // Test if loop executes body multiple times for readMaster
  @Test
  void ReadMasterLoop3(){
    String[] accounts;
    Read read = new Read();
    // Master txt file
    accounts = read.readMaster("Master.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000",
    "20002 TestMasterFile2      A 00100000 0000","30003 TestMasterFile2      D 00100000 0000"}, accounts);
  }
  
  /* Tests for decision coverage */
  
  // Test if bank account number is null
  // bank account number for 2nd line is null
  @Test
  void ReadMasterDecision1(){
    String[] accounts;
    Read read = new Read();
    accounts = read.readMaster("test_skip_2.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000"
          ,"30003 TestMasterFile2      D 00100000 0000"}, accounts);
  }
  
  // Test if bank account number is not null
  @Test
  void ReadMasterDecision2(){
    String[] accounts;
    Read read = new Read();
    // Master txt file
    accounts = read.readMaster("Master.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000"
            ,"20002 TestMasterFile2      A 00100000 0000","30003 TestMasterFile2      D 00100000 0000"}, accounts);
  }
  
  // Test if readMaster can't read in the file
  // putting in nonexistent file so readMaster can't open it
  // null because catch doesnt do anything right now
  @Test
  void ReadMasterDecision3(){
    Read read = new Read();
    Assertions.assertEquals(new String[]{}, read.readMaster("nonExistent.txt"));
  }
}