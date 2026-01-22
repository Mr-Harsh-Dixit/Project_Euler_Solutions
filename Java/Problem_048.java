public class Main {

    static long modPow(long a, long e, long mod) {
        long res = 1 % mod;
        a %= mod;
        while (e > 0) {
            if ((e & 1) == 1) res = mulMod(res, a, mod);
            a = mulMod(a, a, mod);
            e >>= 1;
        }
        return res;
    }

    // safe multiply mod without overflow using long (since mod=1e10 fits, but products can overflow)
    static long mulMod(long x, long y, long mod) {
        long res = 0;
        x %= mod;
        y %= mod;
        while (y > 0) {
            if ((y & 1) == 1) res = (res + x) % mod;
            x = (x * 2) % mod;
            y >>= 1;
        }
        return res;
    }

    public static void main(String[] args) {
        final long MOD = 10_000_000_000L;
        long total = 0;

        for (int i = 1; i <= 1000; i++) {
            total = (total + modPow(i, i, MOD)) % MOD;
        }

        System.out.printf("%010d%n", total); // 9110846700
    }
}
