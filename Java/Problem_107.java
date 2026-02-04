import java.io.*;
import java.util.*;

public class Main {
    static class DSU {
        int[] p, r;
        DSU(int n) {
            p = new int[n];
            r = new int[n];
            for (int i = 0; i < n; i++) p[i] = i;
        }
        int find(int x) {
            while (p[x] != x) {
                p[x] = p[p[x]];
                x = p[x];
            }
            return x;
        }
        boolean union(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return false;
            if (r[ra] < r[rb]) { int t = ra; ra = rb; rb = t; }
            p[rb] = ra;
            if (r[ra] == r[rb]) r[ra]++;
            return true;
        }
    }

    static class Edge implements Comparable<Edge> {
        int w, u, v;
        Edge(int w, int u, int v){ this.w=w; this.u=u; this.v=v; }
        public int compareTo(Edge o){ return Integer.compare(this.w, o.w); }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("network.txt"));
        ArrayList<String[]> rows = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null) rows.add(line.trim().split(","));
        br.close();

        int n = rows.size();
        ArrayList<Edge> edges = new ArrayList<>();
        long total = 0;

        for (int i = 0; i < n; i++) {
            String[] row = rows.get(i);
            for (int j = i + 1; j < n; j++) {
                String v = row[j];
                if (!v.equals("-")) {
                    int w = Integer.parseInt(v);
                    total += w;
                    edges.add(new Edge(w, i, j));
                }
            }
        }

        Collections.sort(edges);
        DSU dsu = new DSU(n);

        long mst = 0;
        int used = 0;
        for (Edge e : edges) {
            if (dsu.union(e.u, e.v)) {
                mst += e.w;
                used++;
                if (used == n - 1) break;
            }
        }

        System.out.println(total - mst); // 259679 for official file
    }
}
