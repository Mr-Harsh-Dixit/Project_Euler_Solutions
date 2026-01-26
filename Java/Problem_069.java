public class Euler69 {
    static boolean isPrime(int x) {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (int i = 3; (long)i*i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }

    static int nextPrime(int p) {
        int x = p + 1;
        while (!isPrime(x)) x++;
        return x;
    }

    public static void main(String[] args) {
        final int LIMIT = 1_000_000;
        long n = 1;
        int p = 2;

        while (n * (long)p <= LIMIT) {
            n *= p;
            p = nextPrime(p);
        }

        System.out.println(n); // 510510
    }
}
