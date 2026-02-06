public class Main {
    static long ways(int n, int m) {
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i >= m) dp[i] += dp[i - m];
        }
        return dp[n] - 1; // exclude all-grey
    }

    public static void main(String[] args) {
        int n = 50;
        long ans = ways(n, 2) + ways(n, 3) + ways(n, 4);
        System.out.println(ans); // 20492570929
    }
}
