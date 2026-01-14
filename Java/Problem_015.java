import java.math.BigInteger;

public class Main {
    private static BigInteger nCr(int n, int r) {
        r = Math.min(r, n - r);
        BigInteger res = BigInteger.ONE;

        for (int i = 1; i <= r; i++) {
            res = res.multiply(BigInteger.valueOf(n - r + i))
                     .divide(BigInteger.valueOf(i)); // exact division
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(nCr(40, 20)); // 137846528820
    }
}
