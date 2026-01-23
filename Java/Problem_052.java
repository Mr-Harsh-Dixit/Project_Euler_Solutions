import java.util.Arrays;

public class Euler52 {

    static int[] signature(int x) {
        int[] cnt = new int[10];
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        return cnt;
    }

    static boolean sameSig(int[] a, int[] b) {
        return Arrays.equals(a, b);
    }

    static int solve() {
        for (int n = 1; ; n++) {
            int low = 1;
            for (int i = 1; i < n; i++) low *= 10;

            int p10 = 1;
            for (int i = 0; i < n; i++) p10 *= 10;

            int high = (p10 - 1) / 6;

            for (int x = low; x <= high; x++) {
                int[] sig = signature(x);
                boolean ok = true;

                for (int k = 2; k <= 6; k++) {
                    if (!sameSig(signature(k * x), sig)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return x;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(solve()); // 142857
    }
}
