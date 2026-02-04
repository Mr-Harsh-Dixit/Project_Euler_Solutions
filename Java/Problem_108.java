public class Main {
    static final int[] PRIMES = {2,3,5,7,11,13,17,19,23,29};
    static final long TARGET = 2000;
    static long best = Long.MAX_VALUE;

    static void dfs(int idx, int maxExp, long n, long divprod) {
        if (divprod > TARGET) {
            if (n < best) best = n;
            return;
        }
        if (idx >= PRIMES.length || n >= best) return;

        long p = PRIMES[idx];
        long val = 1;
        for (int e = 1; e <= maxExp; e++) {
            val *= p;
            if (n > best / val) break; // overflow-safe bound
            long nn = n * val;
            dfs(idx + 1, e, nn, divprod * (2L * e + 1));
        }
    }

    public static void main(String[] args) {
        dfs(0, 60, 1L, 1L);
        System.out.println(best); // 180180
    }
}
