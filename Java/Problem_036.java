public class Main {

    static boolean isPal(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) return false;
        }
        return true;
    }

    static String toBinary(int n) {
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            sb.append((n & 1) == 1 ? '1' : '0');
            n >>= 1;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        final int LIMIT = 1_000_000;
        long total = 0;

        for (int n = 1; n < LIMIT; n += 2) { // only odd
            String dec = Integer.toString(n);
            if (!isPal(dec)) continue;

            String bin = toBinary(n);
            if (isPal(bin)) total += n;
        }

        System.out.println(total); // 872187
    }
}
