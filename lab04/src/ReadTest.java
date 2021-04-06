import org.junit.Test;
import org.junit.jupiter.api.Assertions;

class ReadTest {
  
  /* Tests for loop coverage */
  /* Tests according to while box testing II lecture */
  
  // Tests if loop executes body 0 times for readMaster
  @Test
  void readMasterLoop_0(){
    BankAccount[] accounts;
    Read read = new Read();
    // empty txt file
    accounts = read.readMaster("empty.txt");
    Assertions.assertEquals(null, read.readMaster("empty.txt"));
  }
  
  void readMasterLoop_1(){
    BankAccount[] accounts;
    Read read = new Read();
    // empty txt file
    accounts = read.readMaster("test1.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000"}, read.readMaster("Master.txt"));
  }
  
  // Test if loop executes body multiple times for readMaster
  @Test
  void readMasterLoop_M(){
    BankAccount[] accounts;
    Read read = new Read();
    // Master txt file
    accounts = read.readMaster("Master.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000",
    "20002 TestMasterFile2      A 00100000 0000","30003 TestMasterFile2      D 00100000 0000"}, read.readMaster("Master.txt"));
  }
  
  /* Tests for decision coverage */
  
  // Test if bank account number is null
  // bank account number for 2nd line is null
  @Test
  void readMasterDecision_1(){
    BankAccount[] accounts;
    Read read = new Read();
    accounts = read.readMaster("test_skip_2.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000"
          ,"30003 TestMasterFile2      D 00100000 0000"}, read.readMaster("Master.txt"));
  }
  
  // Test if bank account number is not null
  @Test
  void readMasterDecision_2(){
    BankAccount[] accounts;
    Read read = new Read();
    // Master txt file
    accounts = read.readMaster("Master.txt");
    Assertions.assertArrayEquals(new String[]{"10001 TestMasterFile       A 00100000 0000"
            ,"20002 TestMasterFile2      A 00100000 0000","30003 TestMasterFile2      D 00100000 0000"}, read.readMaster("Master.txt"));
  }
  
  // Test if readMaster can't read in the file
  // putting in nonexistent file so readMaster can't open it
  // null because catch doesnt do anything right now
  @Test
  void readMasterDecision_3(){
    BankAccount[] accounts;
    Read read = new Read();
    Assertions.assertEquals(null, read.readMaster("nonExistent.txt"));
  }
}