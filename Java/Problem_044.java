public class Main {

    static long pent(long n) {
        return n * (3L * n - 1) / 2;
    }

    static boolean isPent(long x) {
        long disc = 1L + 24L * x;
        long s = (long)Math.sqrt(disc);
        // fix possible rounding down
        while (s * s < disc) s++;
        while (s * s > disc) s--;
        return s * s == disc && (1 + s) % 6 == 0;
    }

    public static void main(String[] args) {
        long best = Long.MAX_VALUE;

        for (long k = 2;; k++) {
            long pk = pent(k);

            for (long j = k - 1; j >= 1; j--) {
                long pj = pent(j);
                long d = pk - pj;
                if (d >= best) break;

                if (isPent(d) && isPent(pk + pj)) {
                    best = d;
                }
            }

            if (best != Long.MAX_VALUE) {
                long minNextDiff = pent(k) - pent(k - 1);
                if (minNextDiff > best) break;
            }
        }

        System.out.println(best); // 5482660
    }
}
