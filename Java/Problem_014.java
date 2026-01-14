import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        final int limit = 1_000_000;
        int[] cache = new int[limit + 1];
        cache[1] = 1;

        int bestStart = 1;
        int bestLen = 1;

        ArrayList<Long> path = new ArrayList<>(300);

        for (int start = 2; start < limit; start++) {
            long n = start;
            path.clear();

            while (n != 1 && (n > limit || cache[(int) n] == 0)) {
                path.add(n);
                if ((n & 1L) == 0) n >>= 1;
                else n = 3 * n + 1;
            }

            int total = (n == 1) ? 1 : cache[(int) n];

            for (int i = path.size() - 1; i >= 0; i--) {
                total++;
                long x = path.get(i);
                if (x <= limit) cache[(int) x] = total;
            }

            if (cache[start] > bestLen) {
                bestLen = cache[start];
                bestStart = start;
            }
        }

        System.out.println(bestStart); // 837799
    }
}
