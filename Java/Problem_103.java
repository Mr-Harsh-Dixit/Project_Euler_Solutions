import java.util.*;

public class Main {
    static boolean rule2PrefixSuffix(int[] a) {
        int[] b = a.clone();
        Arrays.sort(b);
        int n = b.length;

        for (int k = 1; k <= n / 2; k++) {
            long left = 0, right = 0;
            for (int i = 0; i <= k; i++) left += b[i];        // k+1 smallest
            for (int i = 0; i < k; i++) right += b[n - 1 - i];// k largest
            if (left <= right) return false;
        }
        return true;
    }

    static boolean rule1Disjoint(int[] a) {
        int n = a.length;
        HashMap<Long, Integer> seen = new HashMap<>(1 << n);

        for (int mask = 1; mask < (1 << n); mask++) {
            long s = 0;
            int m = mask, idx = 0;
            while (m != 0) {
                if ((m & 1) != 0) s += a[idx];
                idx++;
                m >>= 1;
            }

            Integer prev = seen.get(s);
            if (prev == null) {
                seen.put(s, mask);
            } else {
                if ( (prev & mask) == 0 ) return false; // disjoint equal sum
            }
        }
        return true;
    }

    static boolean isSpecial(int[] a) {
        return rule2PrefixSuffix(a) && rule1Disjoint(a);
    }

    public static void main(String[] args) {
        int[] best = {20,31,38,39,40,42,45};
        if (!isSpecial(best)) throw new RuntimeException("Not special.");

        StringBuilder sb = new StringBuilder();
        for (int x : best) sb.append(x);
        System.out.println(sb.toString()); // 20313839404245
    }
}
