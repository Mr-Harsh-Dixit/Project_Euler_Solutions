public class Main {

    static int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public static void main(String[] args) {
        final int LIMIT = 1000;
        int[] cnt = new int[LIMIT + 1];

        for (int m = 2; 2 * m * (m + 1) <= LIMIT; m++) {
            for (int n = 1; n < m; n++) {
                if (((m - n) & 1) == 0) continue;
                if (gcd(m, n) != 1) continue;

                int p0 = 2 * m * (m + n);
                for (int p = p0; p <= LIMIT; p += p0) {
                    cnt[p]++;
                }
            }
        }

        int bestP = 0, bestCnt = 0;
        for (int p = 1; p <= LIMIT; p++) {
            if (cnt[p] > bestCnt) {
                bestCnt = cnt[p];
                bestP = p;
            }
        }

        System.out.println(bestP); // 840
    }
}
