import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger fact = BigInteger.ONE;

        for (int i = 2; i <= 100; i++) {
            fact = fact.multiply(BigInteger.valueOf(i));
        }

        String s = fact.toString();
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += s.charAt(i) - '0';
        }

        System.out.println(sum); // 648
    }
}
