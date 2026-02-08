import java.util.*;

public class Main {
    public static void main(String[] args) {
        final int N = 100000;
        final int K = 10000;

        int[] rad = new int[N + 1];
        Arrays.fill(rad, 1);

        for (int p = 2; p <= N; p++) {
            if (rad[p] == 1) { // prime
                for (int m = p; m <= N; m += p) {
                    rad[m] *= p;
                }
            }
        }

        int[][] arr = new int[N][2];
        for (int n = 1; n <= N; n++) {
            arr[n - 1][0] = rad[n];
            arr[n - 1][1] = n;
        }

        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        System.out.println(arr[K - 1][1]); // 21417
    }
}
