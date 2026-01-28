import java.io.*;
import java.util.*;

public class Euler79 {
    public static void main(String[] args) throws Exception {
        List<String> attempts = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader("keylog.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (!line.isEmpty()) attempts.add(line);
            }
        }

        boolean[] used = new boolean[10];
        boolean[][] adj = new boolean[10][10];
        int[] indeg = new int[10];

        for (String t : attempts) {
            int a = t.charAt(0) - '0';
            int b = t.charAt(1) - '0';
            int c = t.charAt(2) - '0';
            used[a] = used[b] = used[c] = true;

            if (!adj[a][b]) { adj[a][b] = true; indeg[b]++; }
            if (!adj[b][c]) { adj[b][c] = true; indeg[c]++; }
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int d = 0; d <= 9; d++) {
            if (used[d] && indeg[d] == 0) pq.add(d);
        }

        StringBuilder res = new StringBuilder();
        while (!pq.isEmpty()) {
            int u = pq.poll();
            res.append((char)('0' + u));
            for (int v = 0; v <= 9; v++) {
                if (adj[u][v]) {
                    indeg[v]--;
                    if (indeg[v] == 0) pq.add(v);
                }
            }
        }

        System.out.println(res.toString()); // 73162890 for official file
    }
}
