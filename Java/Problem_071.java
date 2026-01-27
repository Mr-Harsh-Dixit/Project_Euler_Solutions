public class Euler71 {
    public static void main(String[] args) {
        final int LIMIT = 1_000_000;
        long bestN = 0, bestD = 1;

        for (long d = 2; d <= LIMIT; d++) {
            long n = (3 * d - 1) / 7; // largest n/d < 3/7
            if (n * bestD > bestN * d) {
                bestN = n;
                bestD = d;
            }
        }

        System.out.println(bestN); // 428570
    }
}
