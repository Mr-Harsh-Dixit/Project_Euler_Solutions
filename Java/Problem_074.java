import java.util.*;

public class Euler74 {
    static int next(int x, int[] fact) {
        if (x == 0) return fact[0];
        int s = 0;
        while (x > 0) {
            s += fact[x % 10];
            x /= 10;
        }
        return s;
    }

    public static void main(String[] args) {
        final int LIMIT = 1_000_000;

        int[] fact = new int[10];
        fact[0] = 1;
        for (int i = 1; i <= 9; i++) fact[i] = fact[i - 1] * i;

        final int MAX = 7 * fact[9]; // 2,540,160
        int[] memo = new int[MAX + 1];

        class Solver {
            int chainLen(int start) {
                ArrayList<Integer> path = new ArrayList<>();
                HashMap<Integer, Integer> pos = new HashMap<>(80);

                int x = start;
                while (true) {
                    if (x <= MAX && memo[x] != 0) {
                        int known = memo[x];
                        for (int i = path.size() - 1; i >= 0; i--) {
                            known += 1;
                            int v = path.get(i);
                            if (v <= MAX) memo[v] = known;
                        }
                        return (start <= MAX) ? memo[start] : path.size() + memo[x];
                    }

                    Integer where = pos.get(x);
                    if (where != null) {
                        int loopStart = where;
                        int loopLen = path.size() - loopStart;

                        for (int i = loopStart; i < path.size(); i++) {
                            int v = path.get(i);
                            if (v <= MAX) memo[v] = loopLen;
                        }

                        int dist = loopLen;
                        for (int i = loopStart - 1; i >= 0; i--) {
                            dist += 1;
                            int v = path.get(i);
                            if (v <= MAX) memo[v] = dist;
                        }

                        return (start <= MAX) ? memo[start] : path.size();
                    }

                    pos.put(x, path.size());
                    path.add(x);
                    x = next(x, fact);
                }
            }
        }

        Solver solver = new Solver();

        int count = 0;
        for (int n = 1; n < LIMIT; n++) {
            if (solver.chainLen(n) == 60) count++;
        }

        System.out.println(count); // 402
    }
}
