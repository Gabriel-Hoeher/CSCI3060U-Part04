public class Error {
    //prints error report if an exception
    public boolean failedConstraintErrorCheck(Exception error) {
        String method = error.getStackTrace()[0].toString().split("\\.")[1].split("\\(")[0];
        boolean isException = error.getClass().getCanonicalName().toString().contains("Exception");

        if (isException) {
            System.out.println("ERROR:\n\tType:\t\t" + error.getClass().getCanonicalName() +
                                "(Exception)\n\tDescription:\t" + error.getMessage() + "\n\tMethod Name:\t" + method);
        }
        return isException;
    }

    //prints error report if a fatal error
    public boolean fatalErrorCheck(Exception error) {
        String file = error.getStackTrace()[0].toString().split("\\.")[0];
        boolean isFatal = error.getClass().getCanonicalName().toString().contains("Error");

        if (isFatal) {
            System.out.println("ERROR:\n\tType:\t\t" + error.getClass().getCanonicalName() +
                                "(Fatal)\n\tDescription:\t" + error.getMessage() + "\n\tFile Name:\t" + file + ".java");
        }
        return isFatal;
    }

    // //basic exception test
    // public static void main(String[] args) {

    //     try {
    //         int num[] = {1, 2, 3, 4};
    //         System.out.println(num[5]);
    //     } catch (Exception e) {
    //         Error error = new Error();
    //         boolean res = error.fatalErrorCheck(e);
    //         System.out.println(res);
    //     }
    // }
}