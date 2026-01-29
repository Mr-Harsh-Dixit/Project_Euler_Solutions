import java.io.*;
import java.util.*;

public class Euler81 {
    public static void main(String[] args) throws Exception {
        List<long[]> rows = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("matrix.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                long[] r = new long[parts.length];
                for (int i = 0; i < parts.length; i++) r[i] = Long.parseLong(parts[i]);
                rows.add(r);
            }
        }

        int n = rows.size();
        long[][] a = new long[n][n];
        for (int i = 0; i < n; i++) a[i] = rows.get(i);

        long[][] dp = new long[n][n];
        dp[0][0] = a[0][0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + a[i][0];
            dp[0][i] = dp[0][i - 1] + a[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = a[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        System.out.println(dp[n - 1][n - 1]); // 427337
    }
}
