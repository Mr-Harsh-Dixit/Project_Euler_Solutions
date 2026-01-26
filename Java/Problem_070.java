import java.util.*;

public class Euler70 {
    static int[] sieve(int limit) {
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; (long)i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) isPrime[j] = false;
            }
        }

        int count = 0;
        for (int i = 2; i <= limit; i++) if (isPrime[i]) count++;
        int[] primes = new int[count];
        int idx = 0;
        for (int i = 2; i <= limit; i++) if (isPrime[i]) primes[idx++] = i;
        return primes;
    }

    static int[] sig(int x) {
        int[] c = new int[10];
        while (x > 0) {
            c[x % 10]++;
            x /= 10;
        }
        return c;
    }

    static boolean sameSig(int a, int b) {
        return Arrays.equals(sig(a), sig(b));
    }

    public static void main(String[] args) {
        final int LIMIT = 10_000_000;
        int[] primes = sieve(LIMIT);

        long bestN = 0;
        long bestNum = 1;
        long bestDen = 0;

        for (int i = 0; i < primes.length; i++) {
            long p = primes[i];
            if (p * p >= LIMIT) break;

            for (int j = i; j < primes.length; j++) {
                long q = primes[j];
                long n = p * q;
                if (n >= LIMIT) break;

                long phi = (p - 1) * (q - 1);

                if (sameSig((int)n, (int)phi)) {
                    if (bestDen == 0 || n * bestDen < bestNum * phi) {
                        bestN = n;
                        bestNum = n;
                        bestDen = phi;
                    }
                }
            }
        }

        System.out.println(bestN); // 8319823
    }
}
