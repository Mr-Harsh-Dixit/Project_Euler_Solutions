import java.util.*;

public class Euler88 {
    static final int KMAX = 12000;
    static final int LIMIT = 2 * KMAX;
    static int[] best = new int[KMAX + 1];

    static void dfs(int start, int prod, int sum, int m) {
        int k = m + (prod - sum);
        if (k <= KMAX) best[k] = Math.min(best[k], prod);

        for (int f = start; f * prod <= LIMIT; f++) {
            dfs(f, prod * f, sum + f, m + 1);
        }
    }

    public static void main(String[] args) {
        Arrays.fill(best, Integer.MAX_VALUE);
        dfs(2, 1, 0, 0);

        HashSet<Integer> set = new HashSet<>();
        for (int k = 2; k <= KMAX; k++) set.add(best[k]);

        long ans = 0;
        for (int x : set) ans += x;

        System.out.println(ans); // 7587457
    }
}
