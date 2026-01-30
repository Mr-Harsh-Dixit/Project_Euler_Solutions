import java.util.*;

public class Euler87 {
    static int LIMIT = 50_000_000;

    static List<Integer> sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; (long)i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;
            }
        }
        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) if (isPrime[i]) primes.add(i);
        return primes;
    }

    public static void main(String[] args) {
        List<Integer> primes = sieve(7071);

        ArrayList<Integer> sq = new ArrayList<>();
        ArrayList<Integer> cube = new ArrayList<>();
        ArrayList<Integer> four = new ArrayList<>();

        for (int p : primes) {
            long p2 = 1L * p * p;
            if (p2 < LIMIT) sq.add((int)p2);

            long p3 = p2 * p;
            if (p3 < LIMIT) cube.add((int)p3);

            long p4 = p2 * p2;
            if (p4 < LIMIT) four.add((int)p4);
        }

        Collections.sort(sq);
        Collections.sort(cube);
        Collections.sort(four);

        boolean[] seen = new boolean[LIMIT];

        for (int f : four) {
            for (int c : cube) {
                int fc = f + c;
                if (fc >= LIMIT) break;

                for (int s : sq) {
                    int v = fc + s;
                    if (v >= LIMIT) break;
                    seen[v] = true;
                }
            }
        }

        int ans = 0;
        for (boolean b : seen) if (b) ans++;
        System.out.println(ans); // 1097343
    }
}
