import java.math.BigInteger;

public class Euler80 {
    static BigInteger isqrt(BigInteger n) {
        if (n.signum() == 0) return BigInteger.ZERO;

        BigInteger x = BigInteger.ONE.shiftLeft((n.bitLength() + 1) / 2);
        while (true) {
            BigInteger y = x.add(n.divide(x)).shiftRight(1);
            if (y.compareTo(x) >= 0) return x;
            x = y;
        }
    }

    static boolean isSquare(int n) {
        int r = (int)Math.sqrt(n);
        return r * r == n;
    }

    public static void main(String[] args) {
        BigInteger TEN = BigInteger.TEN;
        BigInteger scale = TEN.pow(200);

        long total = 0;

        for (int n = 1; n <= 100; n++) {
            if (isSquare(n)) continue;

            BigInteger big = BigInteger.valueOf(n).multiply(scale);
            BigInteger root = isqrt(big);

            String s = root.toString();
            s = s.substring(0, 100); // first 100 digits (includes integer part)
            for (int i = 0; i < s.length(); i++) total += (s.charAt(i) - '0');
        }

        System.out.println(total); // 40886
    }
}
