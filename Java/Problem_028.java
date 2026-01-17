public class Main {
    public static void main(String[] args) {
        final int N = 1001;
        long total = 1;

        for (long n = 3; n <= N; n += 2) {
            total += 4 * n * n - 6 * (n - 1);
        }

        System.out.println(total); // 669171001
    }
}
