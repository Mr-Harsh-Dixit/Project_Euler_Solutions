public class Euler97 {
    static final long MOD = 10_000_000_000L; // 1e10

    static long modPow(long base, long exp) {
        long res = 1L;
        base %= MOD;
        while (exp > 0) {
            if ((exp & 1L) == 1L) res = mulMod(res, base);
            base = mulMod(base, base);
            exp >>= 1;
        }
        return res;
    }

    // Safe modular multiply without BigInteger
    // Uses long since MOD < 2^34, but intermediate can overflow, so do it via splitting.
    static long mulMod(long a, long b) {
        // (a*b) % MOD using 128-bit emulation via BigInteger is banned,
        // so we do "Russian peasant" multiplication (add-and-double).
        long res = 0;
        a %= MOD;
        b %= MOD;
        while (b > 0) {
            if ((b & 1L) == 1L) {
                res = (res + a) % MOD;
            }
            a = (a * 2) % MOD;
            b >>= 1;
        }
        return res;
    }

    public static void main(String[] args) {
        long p = modPow(2, 7_830_457L);
        long ans = (mulMod(28_433L, p) + 1) % MOD;
        System.out.printf("%010d%n", ans); // 8739992577
    }
}
