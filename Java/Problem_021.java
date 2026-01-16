public class Main {
    public static void main(String[] args) {
        final int N = 10000;
        int[] d = new int[N];

        for (int i = 1; i <= N / 2; i++) {
            for (int j = 2 * i; j < N; j += i) {
                d[j] += i;
            }
        }

        long sum = 0;
        for (int a = 2; a < N; a++) {
            int b = d[a];
            if (b != a && b < N && d[b] == a) {
                sum += a;
            }
        }

        System.out.println(sum); // 31626
    }
}
