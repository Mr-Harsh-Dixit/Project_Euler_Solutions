import java.util.*;

public class Main {

    static boolean[] sieve(int limit) {
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; (long)p * p <= limit; p++) {
            if (isPrime[p]) {
                for (long x = (long)p * p; x <= limit; x += p) {
                    isPrime[(int)x] = false;
                }
            }
        }
        return isPrime;
    }

    public static void main(String[] args) {
        final int LIMIT = 2_000_000;
        boolean[] isPrime = sieve(LIMIT);

        ArrayList<Integer> primesB = new ArrayList<>();
        for (int b = 2; b <= 1000; b++) if (isPrime[b]) primesB.add(b);

        int bestLen = 0;
        int bestProd = 0;

        for (int b : primesB) {
            for (int a = -999; a <= 999; a++) {
                int v1 = 1 + a + b;
                if (v1 <= 1 || !isPrime[v1]) continue;

                int n = 0;
                while (true) {
                    long val = 1L * n * n + 1L * a * n + b;
                    if (val <= 1 || val > LIMIT || !isPrime[(int)val]) break;
                    n++;
                }

                if (n > bestLen) {
                    bestLen = n;
                    bestProd = a * b;
                }
            }
        }

        System.out.println(bestProd); // -59231
    }
}
