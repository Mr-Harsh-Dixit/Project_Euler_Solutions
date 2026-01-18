public class Main {

    static int factorial(int x) {
        int f = 1;
        for (int i = 2; i <= x; i++) f *= i;
        return f;
    }

    public static void main(String[] args) {
        int[] fact = new int[10];
        for (int d = 0; d <= 9; d++) fact[d] = factorial(d);

        int limit = 7 * fact[9]; // 2540160
        long total = 0;

        for (int n = 3; n <= limit; n++) {
            int s = 0;
            int x = n;
            while (x > 0) {
                s += fact[x % 10];
                x /= 10;
            }
            if (s == n) total += n;
        }

        System.out.println(total); // 40730
    }
}
