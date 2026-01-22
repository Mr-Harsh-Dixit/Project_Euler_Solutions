import java.util.*;

public class Main {
    public static void main(String[] args) {
        final int LIMIT = 1_000_000;
        int[] cnt = new int[LIMIT + 1];

        for (int i = 2; i <= LIMIT; i++) {
            if (cnt[i] == 0) { // prime
                for (int m = i; m <= LIMIT; m += i) {
                    cnt[m]++;
                }
            }
        }

        int streak = 0;
        for (int n = 2; n <= LIMIT; n++) {
            if (cnt[n] == 4) {
                streak++;
                if (streak == 4) {
                    System.out.println(n - 3); // 134043
                    return;
                }
            } else {
                streak = 0;
            }
        }
    }
}
