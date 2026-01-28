import java.util.*;

public class Euler78 {
    public static void main(String[] args) {
        final int MOD = 1_000_000;

        ArrayList<Integer> p = new ArrayList<>(60000);
        p.add(1); // p(0)

        for (int n = 1; ; n++) {
            long total = 0;

            for (int k = 1; ; k++) {
                int g1 = k * (3 * k - 1) / 2;
                if (g1 > n) break;
                int g2 = k * (3 * k + 1) / 2;

                int sign = (k & 1) == 1 ? 1 : -1;

                total += sign * p.get(n - g1);
                if (g2 <= n) total += sign * p.get(n - g2);
            }

            int val = (int)(total % MOD);
            if (val < 0) val += MOD;

            p.add(val);
            if (val == 0) {
                System.out.println(n); // 55374
                return;
            }
        }
    }
}
