import java.util.*;

public class Main {

    static long factorial(int n) {
        long f = 1;
        for (int i = 2; i <= n; i++) f *= i;
        return f;
    }

    public static void main(String[] args) {
        ArrayList<Character> digits = new ArrayList<>();
        for (char c = '0'; c <= '9'; c++) digits.add(c);

        long k = 1_000_000L - 1; // 0-based
        StringBuilder sb = new StringBuilder(10);

        for (int n = digits.size(); n >= 1; n--) {
            long f = factorial(n - 1);
            int idx = (int)(k / f);
            k %= f;

            sb.append(digits.remove(idx));
        }

        System.out.println(sb.toString()); // 2783915460
    }
}
