public class Euler73 {
    static int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public static void main(String[] args) {
        final int LIMIT = 12000;
        long count = 0;

        for (int d = 2; d <= LIMIT; d++) {
            int nStart = d / 3 + 1;
            int nEnd = (d - 1) / 2;
            for (int n = nStart; n <= nEnd; n++) {
                if (gcd(n, d) == 1) count++;
            }
        }

        System.out.println(count); // 7295372
    }
}
