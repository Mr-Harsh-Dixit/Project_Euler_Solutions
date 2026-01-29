import java.io.*;
import java.util.*;

public class Euler82 {
    public static void main(String[] args) throws Exception {
        List<long[]> rows = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("matrix.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split(",");
                long[] r = new long[parts.length];
                for (int i = 0; i < parts.length; i++) r[i] = Long.parseLong(parts[i]);
                rows.add(r);
            }
        }

        int n = rows.size();
        long[][] a = new long[n][n];
        for (int i = 0; i < n; i++) a[i] = rows.get(i);

        long[] dp = new long[n];
        for (int r = 0; r < n; r++) dp[r] = a[r][0];

        for (int c = 1; c < n; c++) {
            long[] dp2 = new long[n];
            for (int r = 0; r < n; r++) dp2[r] = dp[r] + a[r][c];

            for (int r = 1; r < n; r++) {
                dp2[r] = Math.min(dp2[r], dp2[r - 1] + a[r][c]);
            }
            for (int r = n - 2; r >= 0; r--) {
                dp2[r] = Math.min(dp2[r], dp2[r + 1] + a[r][c]);
            }

            dp = dp2;
        }

        long ans = dp[0];
        for (int r = 1; r < n; r++) ans = Math.min(ans, dp[r]);
        System.out.println(ans); // 260324
    }
}
