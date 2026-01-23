public class Euler53 {
    public static void main(String[] args) {
        final long LIMIT = 1_000_000L;
        final int N = 100;
        long total = 0;

        for (int n = 1; n <= N; n++) {
            long c = 1; // C(n,0)
            for (int r = 1; r <= n / 2; r++) {
                c = (c * (n - r + 1)) / r; // exact division
                if (c > LIMIT) {
                    total += (n - 2L * r + 1);
                    break;
                }
            }
        }

        System.out.println(total); // 4075
    }
}
