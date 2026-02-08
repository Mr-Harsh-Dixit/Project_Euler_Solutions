import java.util.*;

public class Main {
    static final int MAX_K = 200;
    static final int INF = 1_000_000_000;
    static int[] best = new int[MAX_K + 1];

    static boolean done() {
        for (int k = 1; k <= MAX_K; k++) {
            if (best[k] == INF) return false;
        }
        return true;
    }

    static void dfs(ArrayList<Integer> chain, int depth, int limit) {
        int x = chain.get(chain.size() - 1);
        if (depth < best[x]) best[x] = depth;
        if (depth == limit) return;

        for (int i = chain.size() - 1; i >= 0; i--) {
            int nxt = x + chain.get(i);
            if (nxt <= x || nxt > MAX_K) continue;
            int nd = depth + 1;
            if (nd >= best[nxt]) continue;

            chain.add(nxt);
            dfs(chain, nd, limit);
            chain.remove(chain.size() - 1);
        }
    }

    public static void main(String[] args) {
        Arrays.fill(best, INF);
        best[1] = 0;

        int limit = 0;
        while (true) {
            ArrayList<Integer> chain = new ArrayList<>();
            chain.add(1);
            dfs(chain, 0, limit);
            if (done()) break;
            limit++;
        }

        long sum = 0;
        for (int k = 1; k <= MAX_K; k++) sum += best[k];
        System.out.println(sum); // 1582
    }
}
