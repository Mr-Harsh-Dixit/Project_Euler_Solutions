public class Euler76 {
    public static void main(String[] args) {
        final int N = 100;
        long[] dp = new long[N + 1];
        dp[0] = 1;

        for (int part = 1; part <= 99; part++) {
            for (int s = part; s <= N; s++) {
                dp[s] += dp[s - part];
            }
        }

        System.out.println(dp[N]); // 190569291
    }
}
