public class Euler86 {
    static boolean isSquare(long n) {
        long r = (long)Math.sqrt((double)n);
        while (r * r < n) r++;
        while (r * r > n) r--;
        return r * r == n;
    }

    public static void main(String[] args) {
        final long TARGET = 1_000_000;
        long total = 0;
        int M = 0;

        while (total <= TARGET) {
            M++;
            long z = M;
            long zz = z * z;

            for (long s = 2; s <= 2 * z; s++) {
                if (isSquare(s * s + zz)) {
                    long lo = Math.max(1, s - z);
                    long hi = Math.min(z, s / 2);
                    if (hi >= lo) total += (hi - lo + 1);
                }
            }
        }

        System.out.println(M); // 1818
    }
}
