import java.io.*;
import java.util.*;

public class Main {
    static boolean rule2Quick(int[] a) {
        int[] b = a.clone();
        Arrays.sort(b);
        int n = b.length;

        long[] pref = new long[n + 1];
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + b[i];

        for (int k = 1; k <= n / 2; k++) {
            long left = pref[k + 1]; // smallest k+1
            long right = 0;
            for (int i = 0; i < k; i++) right += b[n - 1 - i]; // largest k
            if (left <= right) return false;
        }
        return true;
    }

    static boolean rule1Disjoint(int[] a) {
        int n = a.length;
        HashMap<Long, Integer> seen = new HashMap<>(1 << n);

        for (int mask = 1; mask < (1 << n); mask++) {
            long s = 0;
            int m = mask, i = 0;
            while (m != 0) {
                if ((m & 1) != 0) s += a[i];
                i++;
                m >>= 1;
            }

            Integer prev = seen.get(s);
            if (prev == null) {
                seen.put(s, mask);
            } else {
                if ((prev & mask) == 0) return false; // disjoint equal sum
            }
        }
        return true;
    }

    static boolean isSpecial(int[] a) {
        Arrays.sort(a);
        return rule2Quick(a) && rule1Disjoint(a);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("sets.txt"));
        String line;
        long ans = 0;

        while ((line = br.readLine()) != null) {
            String[] parts = line.trim().split(",");
            int[] a = new int[parts.length];
            for (int i = 0; i < parts.length; i++) a[i] = Integer.parseInt(parts[i]);

            if (isSpecial(a)) {
                long s = 0;
                for (int v : a) s += v;
                ans += s;
            }
        }
        br.close();

        System.out.println(ans); // 73702 
    }
}
