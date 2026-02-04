public class Main {
    static long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = Math.min(r, n - r);
        long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
        }
        return res;
    }

    static long catalan(int k) {
        return comb(2 * k, k) / (k + 1);
    }

    static long neededTests(int n) {
        long total = 0;
        for (int k = 2; k <= n / 2; k++) {
            long waysPick = comb(n, 2 * k);
            long splits = comb(2 * k, k);
            long noncross = catalan(k);
            long need = (splits - 2 * noncross) / 2;
            total += waysPick * need;
        }
        return total;
    }

    public static void main(String[] args) {
        System.out.println(neededTests(12)); // 21384
    }
}
