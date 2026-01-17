public class Main {
    public static void main(String[] args) {
        int[] pow5 = new int[10];
        for (int d = 0; d <= 9; d++) {
            int p = 1;
            for (int i = 0; i < 5; i++) p *= d;
            pow5[d] = p;
        }

        final int limit = 6 * 59049; // 354294
        long total = 0;

        for (int n = 2; n <= limit; n++) {
            int s = 0;
            int x = n;
            while (x > 0) {
                s += pow5[x % 10];
                x /= 10;
            }
            if (s == n) total += n;
        }

        System.out.println(total); // 443839
    }
}
