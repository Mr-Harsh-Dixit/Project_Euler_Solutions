import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger n = BigInteger.valueOf(2).pow(1000);
        String s = n.toString();

        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += s.charAt(i) - '0';
        }

        System.out.println(sum); // 1366
    }
}
