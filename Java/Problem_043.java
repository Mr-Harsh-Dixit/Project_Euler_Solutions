import java.util.*;

public class Main {
    static int[] primes = {17, 13, 11, 7, 5, 3, 2};
    static long total = 0;

    static void dfs(int step, int usedMask, ArrayList<Integer> suffix) {
        if (step == primes.length - 1) {
            // built d2..d10, pick d1
            for (int d = 0; d <= 9; d++) {
                if ((usedMask & (1 << d)) == 0) {
                    long num = d;
                    for (int x : suffix) num = num * 10 + x;
                    total += num;
                    return;
                }
            }
            return;
        }

        int prime = primes[step + 1];
        int a = suffix.get(0), b = suffix.get(1);

        for (int d = 0; d <= 9; d++) {
            if ((usedMask & (1 << d)) != 0) continue;
            int triple = 100 * d + 10 * a + b;
            if (triple % prime == 0) {
                suffix.add(0, d);
                dfs(step + 1, usedMask | (1 << d), suffix);
                suffix.remove(0);
            }
        }
    }

    public static void main(String[] args) {
        // seed with d8d9d10 divisible by 17
        for (int n = 0; n < 1000; n += 17) {
            int a = n / 100;
            int b = (n / 10) % 10;
            int c = n % 10;

            if (a == b || b == c || a == c) continue;

            int used = (1 << a) | (1 << b) | (1 << c);
            ArrayList<Integer> suffix = new ArrayList<>();
            suffix.add(a); suffix.add(b); suffix.add(c);

            dfs(0, used, suffix);
        }

        System.out.println(total); // 16695334890
    }
}
