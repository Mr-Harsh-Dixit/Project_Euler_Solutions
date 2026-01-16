import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger a = BigInteger.ONE; // F1
        BigInteger b = BigInteger.ONE; // F2
        int idx = 2;

        while (b.toString().length() < 1000) {
            BigInteger c = a.add(b);
            a = b;
            b = c;
            idx++;
        }

        System.out.println(idx); // 4782
    }
}
