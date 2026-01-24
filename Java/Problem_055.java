import java.math.BigInteger;

public class Euler55 {
    static boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) return false;
        }
        return true;
    }

    static BigInteger reverseBig(BigInteger x) {
        String s = x.toString();
        StringBuilder sb = new StringBuilder(s).reverse();
        return new BigInteger(sb.toString());
    }

    static boolean isLychrel(int n, int maxIter) {
        BigInteger x = BigInteger.valueOf(n);
        for (int i = 0; i < maxIter; i++) {
            x = x.add(reverseBig(x));
            if (isPalindrome(x.toString())) return false;
        }
        return true;
    }

    static int solve() {
        int count = 0;
        for (int n = 1; n < 10000; n++) {
            if (isLychrel(n, 50)) count++;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(solve()); // 249
    }
}
