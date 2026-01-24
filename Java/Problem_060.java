import java.util.*;

public class Euler60 {
    static long modPow(long a, long e, long mod) {
        long res = 1 % mod;
        a %= mod;
        while (e > 0) {
            if ((e & 1) == 1) res = (res * a) % mod;
            a = (a * a) % mod;
            e >>= 1;
        }
        return res;
    }

    static boolean isPrimeMR(long n) {
        if (n < 2) return false;
        int[] smalls = {2,3,5,7,11,13,17,19,23,29,31,37};
        for (int p : smalls) {
            if (n == p) return true;
            if (n % p == 0) return false;
        }

        long d = n - 1;
        int s = 0;
        while ((d & 1L) == 0) { d >>= 1; s++; }

        int[] bases = {2,3,5,7,11};
        for (int a : bases) {
            if (a % n == 0) continue;
            long x = modPow(a, d, n);
            if (x == 1 || x == n - 1) continue;

            boolean composite = true;
            for (int r = 1; r < s; r++) {
                x = (x * x) % n;
                if (x == n - 1) { composite = false; break; }
            }
            if (composite) return false;
        }
        return true;
    }

    static List<Integer> sieve(int n) {
        boolean[] is = new boolean[n + 1];
        Arrays.fill(is, true);
        is[0] = is[1] = false;
        for (int i = 2; (long)i*i <= n; i++) {
            if (is[i]) for (int j = i*i; j <= n; j += i) is[j] = false;
        }
        ArrayList<Integer> ps = new ArrayList<>();
        for (int i = 2; i <= n; i++) if (is[i]) ps.add(i);
        return ps;
    }

    static int digits10(int x) {
        if (x < 10) return 1;
        if (x < 100) return 2;
        if (x < 1000) return 3;
        if (x < 10000) return 4;
        return 5;
    }

    static ArrayList<Integer> intersect(ArrayList<Integer> a, int start, ArrayList<Integer> b) {
        ArrayList<Integer> out = new ArrayList<>();
        int i = start, j = 0;
        while (i < a.size() && j < b.size()) {
            int ai = a.get(i), bj = b.get(j);
            if (ai == bj) { out.add(ai); i++; j++; }
            else if (ai < bj) i++;
            else j++;
        }
        return out;
    }

    static long bestSum = Long.MAX_VALUE;
    static ArrayList<Integer> bestSet = new ArrayList<>();

    public static void main(String[] args) {
        final int LIMIT = 10000;
        List<Integer> primesAll = sieve(LIMIT);
        ArrayList<Integer> primes = new ArrayList<>();
        for (int p : primesAll) if (p != 2 && p != 5) primes.add(p);

        long[] pow10 = {1,10,100,1000,10000,100000};

        HashMap<Long, Boolean> primeCache = new HashMap<>(300000);

        class Helper {
            long concat(int a, int b) {
                return (long)a * pow10[digits10(b)] + b;
            }
            boolean isPrimeCached(long x) {
                Boolean v = primeCache.get(x);
                if (v != null) return v;
                boolean r = isPrimeMR(x);
                primeCache.put(x, r);
                return r;
            }
            boolean compatible(int a, int b) {
                return isPrimeCached(concat(a,b)) && isPrimeCached(concat(b,a));
            }
        }
        Helper H = new Helper();

        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>(primes.size()*2);
        for (int p : primes) adj.put(p, new ArrayList<>());

        for (int i = 0; i < primes.size(); i++) {
            int p = primes.get(i);
            ArrayList<Integer> list = adj.get(p);
            for (int j = i + 1; j < primes.size(); j++) {
                int q = primes.get(j);
                if (H.compatible(p, q)) list.add(q);
            }
        }

        // DFS clique search
        class DFS {
            void search(ArrayList<Integer> chosen, ArrayList<Integer> cand, long sum) {
                int k = chosen.size();
                if (k == 5) {
                    if (sum < bestSum) {
                        bestSum = sum;
                        bestSet = new ArrayList<>(chosen);
                    }
                    return;
                }
                if (cand.isEmpty() || sum >= bestSum) return;

                int need = 5 - k;
                for (int idx = 0; idx < cand.size(); idx++) {
                    int v = cand.get(idx);
                    if (sum + (long)v * need >= bestSum) break;

                    ArrayList<Integer> newCand = intersect(cand, idx + 1, adj.get(v));
                    chosen.add(v);
                    search(chosen, newCand, sum + v);
                    chosen.remove(chosen.size() - 1);
                }
            }
        }
        DFS dfs = new DFS();

        for (int p : primes) {
            if ((long)p * 5 >= bestSum) break;
            ArrayList<Integer> chosen = new ArrayList<>();
            chosen.add(p);
            dfs.search(chosen, adj.get(p), p);
        }

        System.out.println(bestSum); // 26033
    }
}
