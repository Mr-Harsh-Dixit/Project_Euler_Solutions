import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        String nums = """
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
... (rest of numbers) ...
53503534226472524250874054075591789781264330331690
""";

        BigInteger sum = BigInteger.ZERO;
        for (String line : nums.split("\\R")) {
            if (!line.isBlank()) sum = sum.add(new BigInteger(line.trim()));
        }

        System.out.println(sum.toString().substring(0, 10)); // 5537376230
    }
}
