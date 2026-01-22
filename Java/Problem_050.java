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
        final int LIMIT = 1_000_000;
        boolean[] isPrime = sieve(LIMIT);

        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i < LIMIT; i++) {
            if (isPrime[i]) primes.add(i);
        }

        long[] pref = new long[primes.size() + 1];
        for (int i = 0; i < primes.size(); i++) {
            pref[i + 1] = pref[i] + primes.get(i);
        }

        int bestLen = 0;
        int bestPrime = 0;

        int n = primes.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + bestLen + 1; j <= n; j++) {
                long sum = pref[j] - pref[i];
                if (sum >= LIMIT) break;
                if (isPrime[(int)sum]) {
                    bestLen = j - i;
                    bestPrime = (int)sum;
                }
            }
        }

        System.out.println(bestPrime); // 997651
    }
}
