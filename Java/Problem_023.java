import java.util.*;

public class Main {
    public static void main(String[] args) {
        final int LIMIT = 28123;

        int[] d = new int[LIMIT + 1];
        for (int i = 1; i <= LIMIT / 2; i++) {
            for (int j = 2 * i; j <= LIMIT; j += i) {
                d[j] += i;
            }
        }

        ArrayList<Integer> abundants = new ArrayList<>();
        for (int n = 12; n <= LIMIT; n++) {
            if (d[n] > n) abundants.add(n);
        }

        boolean[] can = new boolean[LIMIT + 1];
        for (int i = 0; i < abundants.size(); i++) {
            int a = abundants.get(i);
            for (int j = i; j < abundants.size(); j++) {
                int s = a + abundants.get(j);
                if (s > LIMIT) break;
                can[s] = true;
            }
        }

        long sum = 0;
        for (int n = 1; n <= LIMIT; n++) {
            if (!can[n]) sum += n;
        }

        System.out.println(sum); // 4179871
    }
}
