import java.math.BigInteger;

public class Main {

    static BigInteger nCr(int n, int r) {
        if (r < 0 || r > n) return BigInteger.ZERO;
        r = Math.min(r, n - r);

        BigInteger res = BigInteger.ONE;
        for (int i = 1; i <= r; i++) {
            res = res.multiply(BigInteger.valueOf(n - r + i))
                     .divide(BigInteger.valueOf(i)); // exact each step
        }
        return res;
    }

    static BigInteger nonBouncyBelow10PowN(int n) {
        BigInteger a = nCr(n + 9, 9);
        BigInteger b = nCr(n + 10, 10);
        BigInteger correction = BigInteger.valueOf(10L).multiply(BigInteger.valueOf(n))
                                          .add(BigInteger.valueOf(2L));
        return a.add(b).subtract(correction);
    }

    public static void main(String[] args) {
        System.out.println(nonBouncyBelow10PowN(100)); // 51161058134250
    }
}
