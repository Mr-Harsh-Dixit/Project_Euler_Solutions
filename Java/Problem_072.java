public class Euler72 {
    public static void main(String[] args) {
        final int N = 1_000_000;
        int[] phi = new int[N + 1];
        for (int i = 0; i <= N; i++) phi[i] = i;

        for (int i = 2; i <= N; i++) {
            if (phi[i] == i) { // prime
                for (int j = i; j <= N; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }

        long ans = 0;
        for (int d = 2; d <= N; d++) ans += phi[d];

        System.out.println(ans); // 303963552391
    }
}
