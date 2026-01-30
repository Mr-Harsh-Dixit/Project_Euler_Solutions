import java.util.*;

public class Euler90 {
    static void expand69(boolean[] b) {
        if (b[6] || b[9]) { b[6] = true; b[9] = true; }
    }

    static List<boolean[]> combinations() {
        List<boolean[]> res = new ArrayList<>();
        int[] d = {0,1,2,3,4,5,6,7,8,9};
        int[] idx = {0,1,2,3,4,5};

        while (true) {
            boolean[] b = new boolean[10];
            for (int k = 0; k < 6; k++) b[d[idx[k]]] = true;
            res.add(b);

            int i = 5;
            while (i >= 0 && idx[i] == 10 - 6 + i) i--;
            if (i < 0) break;
            idx[i]++;
            for (int j = i + 1; j < 6; j++) idx[j] = idx[j - 1] + 1;
        }
        return res;
    }

    public static void main(String[] args) {
        List<boolean[]> cubes = combinations();
        int[][] req = {
            {0,1},{0,4},{0,9},{1,6},{2,5},{3,6},{4,9},{6,4},{8,1}
        };

        long count = 0;
        int n = cubes.size();

        for (int i = 0; i < n; i++) {
            boolean[] A = cubes.get(i).clone();
            expand69(A);

            for (int j = i; j < n; j++) {
                boolean[] B = cubes.get(j).clone();
                expand69(B);

                boolean ok = true;
                for (int[] p : req) {
                    int x = p[0], y = p[1];
                    if (!((A[x] && B[y]) || (A[y] && B[x]))) {
                        ok = false;
                        break;
                    }
                }
                if (ok) count++;
            }
        }

        System.out.println(count); // 1217
    }
}
