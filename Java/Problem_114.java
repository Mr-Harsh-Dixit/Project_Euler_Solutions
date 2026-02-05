public class Main {
    public static void main(String[] args) {
        final int N = 50;
        long[] F = new long[N + 1];
        F[0] = 1;

        for (int i = 1; i <= N; i++) {
            // Leading grey
            F[i] = F[i - 1];

            // Red block k >= 3 followed by grey
            for (int k = 3; k < i; k++) {
                F[i] += F[i - k - 1];
            }

            // Red block reaches the end
            if (i >= 3) F[i] += 1;
        }

        System.out.println(F[N]); // 16475640049
    }
}
