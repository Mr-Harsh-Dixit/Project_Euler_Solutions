import java.util.*;

public class Main {
    public static int firstNExceeding(int m, long target) {
        ArrayList<Long> F = new ArrayList<>();
        ArrayList<Long> P = new ArrayList<>();
        F.add(1L); // F[0]
        P.add(1L); // P[0]

        int n = 0;
        while (F.get(n) <= target) {
            n++;
            long fn;
            if (n < m) {
                fn = 1L;
            } else {
                fn = F.get(n - 1) + 1L + P.get(n - m - 1);
            }
            F.add(fn);
            P.add(P.get(n - 1) + fn);
        }
        return n;
    }

    public static void main(String[] args) {
        System.out.println(firstNExceeding(50, 1_000_000L)); // 168
    }
}
