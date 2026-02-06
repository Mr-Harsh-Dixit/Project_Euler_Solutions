import java.util.*;

public class Main {
    static int digitSum(long n) {
        int s = 0;
        while (n > 0) {
            s += (int)(n % 10);
            n /= 10;
        }
        return s;
    }

    public static void main(String[] args) {
        final long LIMIT = 1_000_000_000_000_000_000L; // 1e18
        HashSet<Long> vals = new HashSet<>(4096);

        for (int s = 2; s <= 500; s++) {
            // use BigInteger-like overflow checks, but we can do safe multiply bounds
            long v = (long)s * (long)s; // s^2
            while (v > 0 && v <= LIMIT) {
                if (v >= 10 && digitSum(v) == s) vals.add(v);

                // overflow-safe: if v * s would exceed LIMIT or overflow long, break
                if (v > LIMIT / s) break;
                v *= s;
            }
        }

        ArrayList<Long> arr = new ArrayList<>(vals);
        Collections.sort(arr);

        System.out.println(arr.get(29)); // 248155780267521
    }
}
