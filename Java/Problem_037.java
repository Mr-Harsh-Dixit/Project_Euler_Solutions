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

    static boolean isTruncatable(int p, boolean[] isPrime) {
        if (p < 10) return false;

        int x = p;
        while (x > 0) {
            if (!isPrime[x]) return false;
            x /= 10;
        }

        String s = Integer.toString(p);
        for (int i = 0; i < s.length(); i++) {
            int v = Integer.parseInt(s.substring(i));
            if (!isPrime[v]) return false;
        }

        return true;
    }

    public static void main(String[] args) {
        final int LIMIT = 1_000_000;
        boolean[] isPrime = sieve(LIMIT);

        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(2); q.add(3); q.add(5); q.add(7);

        ArrayList<Integer> found = new ArrayList<>();
        int[] digits = {1, 3, 7, 9};

        while (found.size() < 11) {
            int n = q.removeFirst();

            for (int d : digits) {
                int m = n * 10 + d;
                if (m <= LIMIT && isPrime[m]) {
                    q.addLast(m);
                    if (isTruncatable(m, isPrime)) found.add(m);
                }
            }
        }

        long sum = 0;
        for (int x : found) sum += x;

        System.out.println(sum); // 748317
    }
}
