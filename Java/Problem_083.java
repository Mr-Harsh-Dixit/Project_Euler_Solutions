import java.io.*;
import java.util.*;

public class Euler83 {
    static class State {
        long d;
        int r, c;
        State(long d, int r, int c) { this.d = d; this.r = r; this.c = c; }
    }

    public static void main(String[] args) throws Exception {
        List<long[]> rows = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader("matrix.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split(",");
                long[] row = new long[parts.length];
                for (int i = 0; i < parts.length; i++) row[i] = Long.parseLong(parts[i]);
                rows.add(row);
            }
        }

        int n = rows.size();
        long[][] a = new long[n][n];
        for (int i = 0; i < n; i++) a[i] = rows.get(i);

        long INF = Long.MAX_VALUE / 4;
        long[][] dist = new long[n][n];
        for (int i = 0; i < n; i++) Arrays.fill(dist[i], INF);

        dist[0][0] = a[0][0];

        PriorityQueue<State> pq = new PriorityQueue<>(Comparator.comparingLong(s -> s.d));
        pq.add(new State(dist[0][0], 0, 0));

        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};

        while (!pq.isEmpty()) {
            State cur = pq.poll();
            long d = cur.d;
            int r = cur.r, c = cur.c;

            if (d != dist[r][c]) continue;
            if (r == n - 1 && c == n - 1) break;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (0 <= nr && nr < n && 0 <= nc && nc < n) {
                    long nd = d + a[nr][nc];
                    if (nd < dist[nr][nc]) {
                        dist[nr][nc] = nd;
                        pq.add(new State(nd, nr, nc));
                    }
                }
            }
        }

        System.out.println(dist[n - 1][n - 1]); // 425185
    }
}
