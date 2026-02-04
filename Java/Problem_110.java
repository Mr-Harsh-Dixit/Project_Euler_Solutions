public class Main {
    static final long TARGET = 8_000_000L;
    static final int[] PRIMES = {2,3,5,7,11,13,17,19,23,29,31};
    static long best = Long.MAX_VALUE;

    static void dfs(int idx, int maxExp, long n, long prod) {
        if (prod > TARGET) {
            if (n < best) best = n;
            return;
        }
        if (idx >= PRIMES.length || n >= best) return;

        long p = PRIMES[idx];
        long val = 1;

        for (int e = 1; e <= maxExp; e++) {
            if (val > best / p) break;
            val *= p;
            if (n > best / val) break;
            long nn = n * val;
            dfs(idx + 1, e, nn, prod * (2L*e + 1));
        }
    }

    public static void main(String[] args) {
        dfs(0, 60, 1L, 1L);
        System.out.println(best); // 9350130049860600
    }
}
