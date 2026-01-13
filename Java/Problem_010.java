public class Main {
    public static void main(String[] args) {
        final int limit = 2_000_000;
        if (limit <= 2) {
            System.out.println(0);
            return;
        }

        // index i => number (2*i + 3)
        int size = (limit - 1) / 2;
        boolean[] isPrime = new boolean[size];
        for (int i = 0; i < size; i++) isPrime[i] = true;

        int root = (int) Math.sqrt(limit - 1);
        int maxI = (root - 3) / 2;

        for (int i = 0; i <= maxI; i++) {
            if (isPrime[i]) {
                int p = 2 * i + 3;
                long start = ((long) p * p - 3) / 2;
                for (long j = start; j < size; j += p) {
                    isPrime[(int) j] = false;
                }
            }
        }

        long sum = 2; // include 2
        for (int i = 0; i < size; i++) {
            if (isPrime[i]) sum += (2L * i + 3);
        }

        System.out.println(sum); // 142913828922
    }
}
