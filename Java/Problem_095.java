import java.util.*;

public class Euler95 {
    public static void main(String[] args) {
        final int N = 1_000_000;

        int[] sumDiv = new int[N + 1];
        for (int i = 1; i <= N / 2; i++) {
            for (int j = i * 2; j <= N; j += i) sumDiv[j] += i;
        }

        boolean[] processed = new boolean[N + 1];

        int bestLen = 0;
        int bestMin = Integer.MAX_VALUE;

        ArrayList<Integer> path = new ArrayList<>(256);

        for (int start = 2; start <= N; start++) {
            if (processed[start]) continue;

            HashMap<Integer, Integer> local = new HashMap<>(128);
            path.clear();

            int cur = start;
            while (cur >= 1 && cur <= N && !processed[cur] && !local.containsKey(cur)) {
                local.put(cur, path.size());
                path.add(cur);
                cur = sumDiv[cur];
            }

            Integer idxObj = local.get(cur);
            if (idxObj != null) {
                int idx = idxObj;
                int clen = path.size() - idx;
                int cmin = Integer.MAX_VALUE;
                for (int k = idx; k < path.size(); k++) cmin = Math.min(cmin, path.get(k));

                if (clen > bestLen || (clen == bestLen && cmin < bestMin)) {
                    bestLen = clen;
                    bestMin = cmin;
                }
            }

            for (int v : path) processed[v] = true;
        }

        System.out.println(bestMin); // 14316
    }
}
