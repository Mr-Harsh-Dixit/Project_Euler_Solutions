import java.lang.Math;

public class Main {
    static final long MOD = 1_000_000_000L;
    static final int TARGET_MASK = (1 << 10) - 2; // bits 1..9 set

    static boolean isPandigital1to9(int x) {
        if (x < 100_000_000) return false;
        int mask = 0;
        for (int i = 0; i < 9; i++) {
            int d = x % 10;
            if (d == 0) return false;
            int bit = 1 << d;
            if ((mask & bit) != 0) return false;
            mask |= bit;
            x /= 10;
        }
        return mask == TARGET_MASK;
    }

    static int first9DigitsFib(long n, double logphi, double logsqrt5) {
        double x = n * logphi - logsqrt5;
        double frac = x - Math.floor(x);
        return (int) Math.pow(10.0, frac + 8.0);
    }

    public static void main(String[] args) {
        double phi = (1.0 + Math.sqrt(5.0)) / 2.0;
        double logphi = Math.log10(phi);
        double logsqrt5 = Math.log10(5.0) / 2.0;

        long a = 1, b = 1; // F1, F2 mod MOD
        long n = 2;

        while (true) {
            n++;
            long c = (a + b) % MOD;
            a = b;
            b = c;

            if (isPandigital1to9((int) b)) {
                int lead = first9DigitsFib(n, logphi, logsqrt5);
                if (isPandigital1to9(lead)) {
                    System.out.println(n); // 329468
                    return;
                }
            }
        }
    }
}
