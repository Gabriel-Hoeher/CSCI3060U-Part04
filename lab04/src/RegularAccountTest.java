
import org.junit.Test;
import org.junit.jupiter.api.Assertions;

class RegularAccountTest {

    /*Tests if no transactions*/
    @Test
    void regularCostTransaction() {
        RegularAccount acc = new RegularAccount("Test",111,10f);
        Assertions.assertEquals(-1,acc.regularCost());
    }

    /*Tests if negative transactions*/
    @Test
    void regularCostTransaction2() {
        RegularAccount acc = new RegularAccount("Test",111,10f);
        acc.totalNumOfTransaction = -1;
        Assertions.assertEquals(-1,acc.regularCost());
    }

    /*Tests it there are multiple transactions*/
    @Test
    void regularCostTransaction3() {
        RegularAccount acc = new RegularAccount("Test",111,10f);
        acc.totalNumOfTransaction = 3;
        Assertions.assertEquals(acc.totalNumOfTransaction * 0.1f,acc.regularCost());
    }

    /*Tests it there is one transactions*/
    @Test
    void regularCostTransaction4() {
        RegularAccount acc = new RegularAccount("Test",111,10f);
        acc.totalNumOfTransaction = 1;
        Assertions.assertEquals(acc.totalNumOfTransaction * 0.1f,acc.regularCost());
    }

    /*Tests if current balance is larger*/
    @Test
    void regularCostBalance() {
        RegularAccount acc = new RegularAccount("Test",111,1f);
        acc.totalNumOfTransaction = 3;
        Assertions.assertEquals(acc.totalNumOfTransaction * 0.1f,acc.regularCost());
    }

    /*Tests if current balance is smaller*/
    @Test
    void regularCostBalance2() {
        RegularAccount acc = new RegularAccount("Test",111,0f);
        acc.totalNumOfTransaction = 3;
        Assertions.assertEquals(-1,acc.regularCost());
    }

    /*Tests if current balance is the same*/
    @Test
    void regularCostBalance3() {
        RegularAccount acc = new RegularAccount("Test",111,0.1f);
        acc.totalNumOfTransaction = 1;
        Assertions.assertEquals(acc.totalNumOfTransaction * 0.1f,acc.regularCost());
    }
}