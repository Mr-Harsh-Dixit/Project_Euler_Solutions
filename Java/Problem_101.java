import java.util.*;

public class Main {
    static long u(long n) {
        long s = 0;
        long sign = 1;
        long p = 1;
        for (int i = 0; i <= 10; i++) {
            s += sign * p;
            sign = -sign;
            p *= n;
        }
        return s;
    }

    static long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
        }
        return res;
    }

    public static void main(String[] args) {
        long[] vals = new long[12]; // 1..11
        for (int n = 1; n <= 11; n++) vals[n] = u(n);

        long ans = 0;

        for (int k = 1; k <= 10; k++) {
            long[] diff = new long[k];
            for (int i = 0; i < k; i++) diff[i] = vals[i + 1];

            long[] firstDiffs = new long[k];
            firstDiffs[0] = diff[0];

            for (int level = 1; level <= k - 1; level++) {
                for (int i = 0; i < k - level; i++) {
                    diff[i] = diff[i + 1] - diff[i];
                }
                firstDiffs[level] = diff[0];
            }

            long pred = 0;
            for (int j = 0; j < k; j++) {
                pred += comb(k, j) * firstDiffs[j];
            }

            if (pred != vals[k + 1]) ans += pred;
        }

        System.out.println(ans); // 37076114526
    }
}
