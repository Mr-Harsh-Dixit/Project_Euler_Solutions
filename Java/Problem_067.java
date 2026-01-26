import java.io.*;
import java.util.*;

public class Euler67 {
    public static void main(String[] args) throws Exception {
        ArrayList<int[]> tri = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("triangle.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;
                String[] parts = line.split("\\s+");
                int[] row = new int[parts.length];
                for (int i = 0; i < parts.length; i++) row[i] = Integer.parseInt(parts[i]);
                tri.add(row);
            }
        }

        int[] dp = tri.get(tri.size() - 1).clone();
        for (int r = tri.size() - 2; r >= 0; r--) {
            int[] row = tri.get(r);
            for (int c = 0; c <= r; c++) {
                dp[c] = row[c] + Math.max(dp[c], dp[c + 1]);
            }
        }

        System.out.println(dp[0]); // 7273 
    }
}
