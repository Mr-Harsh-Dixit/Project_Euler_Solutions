import java.util.*;

public class Main {

    static boolean[] sieve(int limit) {
        boolean[] isPrime = new boolean[limit];
        Arrays.fill(isPrime, true);
        if (limit > 0) isPrime[0] = false;
        if (limit > 1) isPrime[1] = false;

        for (int p = 2; (long)p * p < limit; p++) {
            if (isPrime[p]) {
                for (long x = (long)p * p; x < limit; x += p) {
                    isPrime[(int)x] = false;
                }
            }
        }
        return isPrime;
    }

    static int[] rotations(int n) {
        String s = Integer.toString(n);
        int k = s.length();
        int[] rots = new int[k];
        for (int i = 0; i < k; i++) {
            String t = s.substring(i) + s.substring(0, i);
            rots[i] = Integer.parseInt(t);
        }
        return rots;
    }

    static boolean hasBadDigit(String s) {
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c=='0' || c=='2' || c=='4' || c=='5' || c=='6' || c=='8') return true;
        }
        return false;
    }

    public static void main(String[] args) {
        final int LIMIT = 1_000_000;
        boolean[] isPrime = sieve(LIMIT);
        boolean[] processed = new boolean[LIMIT];

        int total = 0;

        for (int p = 2; p < LIMIT; p++) {
            if (!isPrime[p] || processed[p]) continue;

            int[] rots = rotations(p);
            for (int r : rots) if (r < LIMIT) processed[r] = true;

            String s = Integer.toString(p);
            if (s.length() > 1 && hasBadDigit(s)) continue;

            boolean ok = true;
            for (int r : rots) {
                if (r >= LIMIT || !isPrime[r]) { ok = false; break; }
            }

            if (ok) {
                // count distinct rotations
                int add = 0;
                for (int i = 0; i < rots.length; i++) {
                    boolean seen = false;
                    for (int j = 0; j < i; j++) {
                        if (rots[i] == rots[j]) { seen = true; break; }
                    }
                    if (!seen) add++;
                }
                total += add;
            }
        }

        System.out.println(total); // 55
    }
}
