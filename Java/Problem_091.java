public class Euler91 {
    static long maxSteps(int x, int y, int dx, int dy, int N) {
        long INF = (1L << 60);
        long lim = INF;

        if (dx > 0) lim = Math.min(lim, (long)(N - x) / dx);
        else if (dx < 0) lim = Math.min(lim, (long)x / (-dx));

        if (dy > 0) lim = Math.min(lim, (long)(N - y) / dy);
        else if (dy < 0) lim = Math.min(lim, (long)y / (-dy));

        return (lim == INF) ? 0 : lim;
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public static void main(String[] args) {
        final int N = 50;
        long ans = 1L * N * N; // right angle at origin

        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                if (x == 0 && y == 0) continue;

                int g = gcd(x, y);
                int dx = -y / g;
                int dy =  x / g;

                ans += maxSteps(x, y, dx, dy, N);
                ans += maxSteps(x, y, -dx, -dy, N);
            }
        }

        System.out.println(ans); // 14234
    }
}
