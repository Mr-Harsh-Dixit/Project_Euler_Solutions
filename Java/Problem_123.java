import java.util.*;

public class Main {
    static int[] sieve(int N) {
        boolean[] isPrime = new boolean[N + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; (long)i * i <= N; i++) {
            if (isPrime[i]) {
                for (long j = (long)i * i; j <= N; j += i) {
                    isPrime[(int)j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i <= N; i++) if (isPrime[i]) count++;

        int[] primes = new int[count];
        int idx = 0;
        for (int i = 2; i <= N; i++) if (isPrime[i]) primes[idx++] = i;

        return primes;
    }

    public static void main(String[] args) {
        final long THRESH = 10_000_000_000L;
        int[] primes = sieve(500_000);

        for (int n = 1; n <= primes.length; n++) {
            if ((n & 1) == 1) {
                long p = primes[n - 1];
                if (2L * n * p > THRESH) {
                    System.out.println(n); // 21035
                    return;
                }
            }
        }
        System.out.println("Need bigger sieve");
    }
}
