import java.util.*;

public class Euler58 {
    static int[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; (long)i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;
            }
        }

        int count = 0;
        for (int i = 2; i <= n; i++) if (isPrime[i]) count++;
        int[] primes = new int[count];
        int idx = 0;
        for (int i = 2; i <= n; i++) if (isPrime[i]) primes[idx++] = i;
        return primes;
    }

    static boolean isPrimeFast(long n, int[] primes) {
        if (n < 2) return false;
        for (int p : primes) {
            long pp = (long)p * p;
            if (pp > n) break;
            if (n % p == 0) return n == p;
        }
        return true;
    }

    static long solve() {
        int[] primes = sieve(30000);

        long primeCount = 0;
        long diagTotal = 1;
        int k = 0;

        while (true) {
            k++;
            long s = 2L * k + 1;
            long step = s - 1;
            long sq = s * s;

            long c1 = sq - step;
            long c2 = sq - 2 * step;
            long c3 = sq - 3 * step;

            if (isPrimeFast(c1, primes)) primeCount++;
            if (isPrimeFast(c2, primes)) primeCount++;
            if (isPrimeFast(c3, primes)) primeCount++;

            diagTotal += 4;

            if (primeCount * 10 < diagTotal) return s;
        }
    }

    public static void main(String[] args) {
        System.out.println(solve()); // 26241
    }
}
