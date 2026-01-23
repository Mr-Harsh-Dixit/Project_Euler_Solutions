import java.util.*;

public class Euler51 {

    static boolean[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; (long)i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    static int solve(int limit) {
        boolean[] isPrime = sieve(limit);

        for (int p = 2; p <= limit; p++) {
            if (!isPrime[p]) continue;

            String s = Integer.toString(p);
            int L = s.length();

            for (char d = '0'; d <= '9'; d++) {
                int[] temp = new int[L];
                int k = 0;

                for (int i = 0; i < L; i++) {
                    if (s.charAt(i) == d && i != L - 1) {
                        temp[k++] = i;
                    }
                }
                if (k == 0) continue;

                for (int mask = 1; mask < (1 << k); mask++) {
                    boolean leading = false;
                    char[] pattern = s.toCharArray();

                    for (int j = 0; j < k; j++) {
                        if ((mask & (1 << j)) != 0) {
                            int idx = temp[j];
                            if (idx == 0) leading = true;
                            pattern[idx] = '*';
                        }
                    }

                    int cnt = 0;
                    int smallest = Integer.MAX_VALUE;

                    for (char r = '0'; r <= '9'; r++) {
                        if (leading && r == '0') continue;

                        char[] candChars = pattern.clone();
                        for (int i = 0; i < L; i++) {
                            if (candChars[i] == '*') candChars[i] = r;
                        }

                        int cand = Integer.parseInt(new String(candChars));
                        if (cand <= limit && isPrime[cand]) {
                            cnt++;
                            if (cand < smallest) smallest = cand;
                            if (cnt > 8) break;
                        }
                    }

                    if (cnt == 8 && smallest == p) return p;
                }
            }
        }

        throw new RuntimeException("Not found within limit; increase limit.");
    }

    public static void main(String[] args) {
        System.out.println(solve(2_000_000)); // 121313
    }
}
