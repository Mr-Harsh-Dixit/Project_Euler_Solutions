public class Euler64 {
    public static void main(String[] args) {
        final int LIMIT = 10000;
        int count = 0;

        for (int N = 2; N <= LIMIT; N++) {
            int a0 = (int)Math.sqrt(N);
            if ((long)a0 * a0 == N) continue;

            long m = 0, d = 1, a = a0;
            int period = 0;

            while (true) {
                m = d * a - m;
                d = (N - m * m) / d;
                a = (a0 + m) / d;
                period++;
                if (a == 2L * a0) break;
            }

            if ((period & 1) == 1) count++;
        }

        System.out.println(count); // 1322
    }
}
