import java.util.*;

public class Euler61 {

    static int poly(int s, int n) {
        return ((s - 2) * n * n - (s - 4) * n) / 2;
    }

    static ArrayList<Integer> generate4(int s) {
        ArrayList<Integer> out = new ArrayList<>();
        for (int n = 1;; n++) {
            int v = poly(s, n);
            if (v > 9999) break;
            if (v >= 1000) out.add(v);
        }
        return out;
    }

    public static void main(String[] args) {
        int[] types = {3,4,5,6,7,8};

        HashMap<Integer, ArrayList<Integer>> nums = new HashMap<>();
        HashMap<Integer, HashMap<Integer, ArrayList<Integer>>> edges = new HashMap<>();

        for (int s : types) {
            ArrayList<Integer> list = generate4(s);
            nums.put(s, list);

            HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
            for (int x : list) {
                int pre = x / 100;
                int suf = x % 100;
                if (suf < 10) continue;
                map.computeIfAbsent(pre, k -> new ArrayList<>()).add(x);
            }
            edges.put(s, map);
        }

        class DFS {
            boolean search(ArrayList<Integer> path, boolean[] used, int needPrefix, int startPrefix) {
                if (path.size() == 6) return needPrefix == startPrefix;

                for (int i = 0; i < 6; i++) {
                    if (used[i]) continue;
                    int s = types[i];
                    ArrayList<Integer> cands = edges.get(s).get(needPrefix);
                    if (cands == null) continue;

                    used[i] = true;
                    for (int x : cands) {
                        path.add(x);
                        if (search(path, used, x % 100, startPrefix)) return true;
                        path.remove(path.size() - 1);
                    }
                    used[i] = false;
                }
                return false;
            }
        }

        DFS dfs = new DFS();

        for (int si = 0; si < 6; si++) {
            int startType = types[si];
            for (int start : nums.get(startType)) {
                int sp = start / 100, ss = start % 100;
                if (ss < 10) continue;

                ArrayList<Integer> path = new ArrayList<>();
                path.add(start);
                boolean[] used = new boolean[6];
                used[si] = true;

                if (dfs.search(path, used, ss, sp)) {
                    long sum = 0;
                    for (int v : path) sum += v;
                    System.out.println(sum); // 28684
                    return;
                }
            }
        }
    }
}
