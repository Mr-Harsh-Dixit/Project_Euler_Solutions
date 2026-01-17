import java.math.BigInteger;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        HashSet<BigInteger> set = new HashSet<>();

        for (int a = 2; a <= 100; a++) {
            BigInteger base = BigInteger.valueOf(a);
            for (int b = 2; b <= 100; b++) {
                set.add(base.pow(b));
            }
        }

        System.out.println(set.size()); // 9183
    }
}
