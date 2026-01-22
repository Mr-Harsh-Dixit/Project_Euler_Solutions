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

    static boolean isSquare(long x) {
        long s = (long)Math.sqrt(x);
        while (s * s < x) s++;
        while (s * s > x) s--;
        return s * s == x;
    }

    public static void main(String[] args) {
        final int LIMIT = 100000;
        boolean[] isPrime = sieve(LIMIT);

        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= LIMIT; i++) if (isPrime[i]) primes.add(i);

        for (int n = 9;; n += 2) {
            if (n <= LIMIT && isPrime[n]) continue; // skip primes

            boolean ok = false;
            for (int p : primes) {
                if (p >= n) break;
                int r = n - p;
                if ((r % 2 == 0) && isSquare(r / 2)) {
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                System.out.println(n); // 5777
                break;
            }
        }
    }
}
