public class Euler85 {
    public static void main(String[] args) {
        final long TARGET = 2_000_000L;
        long bestDiff = Long.MAX_VALUE;
        long bestArea = 0;

        for (int m = 1; m <= 2000; m++) {
            long tm = (long)m * (m + 1) / 2;
            double x = (double)TARGET / (double)tm;

            int n0 = (int)((Math.sqrt(1.0 + 8.0 * x) - 1.0) / 2.0);

            int[] cand = {n0, n0 + 1};
            for (int n : cand) {
                if (n <= 0) continue;
                long tn = (long)n * (n + 1) / 2;
                long rect = tm * tn;
                long diff = Math.abs(rect - TARGET);

                if (diff < bestDiff) {
                    bestDiff = diff;
                    bestArea = (long)m * n;
                }
            }
        }

        System.out.println(bestArea); // 2772
    }
}
