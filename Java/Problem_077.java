import java.util.*;

public class Euler77 {
    static int[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;
        for (int i = 2; (long)i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i <= n; i++) if (isPrime[i]) cnt++;
        int[] primes = new int[cnt];
        int idx = 0;
        for (int i = 2; i <= n; i++) if (isPrime[i]) primes[idx++] = i;
        return primes;
    }

    public static void main(String[] args) {
        final int THRESH = 5000;
        int n = 2;

        while (true) {
            int[] primes = sieve(n);
            int[] ways = new int[n + 1];
            ways[0] = 1;

            for (int p : primes) {
                for (int s = p; s <= n; s++) {
                    ways[s] += ways[s - p];
                }
            }

            if (ways[n] > THRESH) {
                System.out.println(n); // 71
                return;
            }
            n++;
        }
    }
}
