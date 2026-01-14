public class Main {

    private static long countDivisors(long x) {
        long total = 1;

        int exp = 0;
        while (x % 2 == 0) {
            x /= 2;
            exp++;
        }
        if (exp > 0) total *= (exp + 1);

        for (long p = 3; p * p <= x; p += 2) {
            exp = 0;
            while (x % p == 0) {
                x /= p;
                exp++;
            }
            if (exp > 0) total *= (exp + 1);
        }

        if (x > 1) total *= 2;

        return total;
    }

    public static void main(String[] args) {
        final long threshold = 500;
        long n = 1;

        while (true) {
            long a, b;
            if (n % 2 == 0) {
                a = n / 2;
                b = n + 1;
            } else {
                a = n;
                b = (n + 1) / 2;
            }

            if (countDivisors(a) * countDivisors(b) > threshold) {
                System.out.println(n * (n + 1) / 2); // 76576500
                return;
            }
            n++;
        }
    }
}
