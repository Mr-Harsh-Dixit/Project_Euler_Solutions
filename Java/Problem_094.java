public class Euler94 {
    static long[] step(long x, long y) {
        // multiply (x + y*sqrt(12)) by (7 + 2*sqrt(12))
        return new long[]{7*x + 24*y, 2*x + 7*y};
    }

    public static void main(String[] args) {
        final long LIMIT = 1_000_000_000L;
        long total = 0;

        // Family 1: x = 3a - 1 (a,a,a+1), seed (14,4)
        {
            long x = 14, y = 4;
            while (true) {
                long a = (x + 1) / 3;
                long p = 3*a + 1;
                if (p > LIMIT) break;
                total += p;
                long[] nxt = step(x, y);
                x = nxt[0]; y = nxt[1];
            }
        }

        // Family 2: x = 3a + 1 (a,a,a-1), seed (52,15)
        {
            long x = 52, y = 15;
            while (true) {
                long a = (x - 1) / 3;
                long p = 3*a - 1;
                if (p > LIMIT) break;
                total += p;
                long[] nxt = step(x, y);
                x = nxt[0]; y = nxt[1];
            }
        }

        System.out.println(total); // 518408346
    }
}
