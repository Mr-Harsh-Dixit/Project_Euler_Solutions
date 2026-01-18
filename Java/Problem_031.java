public class Main {
    public static void main(String[] args) {
        int target = 200;
        int[] coins = {1,2,5,10,20,50,100,200};
        long[] dp = new long[target + 1];
        dp[0] = 1;

        for (int coin : coins) {
            for (int x = coin; x <= target; x++) {
                dp[x] += dp[x - coin];
            }
        }

        System.out.println(dp[target]); // 73682
    }
}
