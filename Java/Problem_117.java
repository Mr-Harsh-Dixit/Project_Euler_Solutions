public class Main {
    public static void main(String[] args) {
        final int N = 50;
        long[] f = new long[N + 1];
        f[0] = 1;

        for (int i = 1; i <= N; i++) {
            long v = f[i - 1];
            if (i >= 2) v += f[i - 2];
            if (i >= 3) v += f[i - 3];
            if (i >= 4) v += f[i - 4];
            f[i] = v;
        }

        System.out.println(f[N]); // 100808458960497
    }
}
