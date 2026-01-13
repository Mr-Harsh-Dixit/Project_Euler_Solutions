public class Main {
    public static void main(String[] args) {
        final int S = 1000;
        final int target = S / 2; // 500

        for (int m = 2; m < 1000; m++) {
            for (int n = 1; n < m; n++) {
                int denom = m * (m + n);
                if (denom > target) break;

                if (target % denom == 0) {
                    int k = target / denom;
                    long a = (long) k * (m * m - n * n);
                    long b = (long) k * (2 * m * n);
                    long c = (long) k * (m * m + n * n);

                    if (a + b + c == S) {
                        System.out.println(a * b * c); // 31875000
                        return;
                    }
                }
            }
        }
    }
}
