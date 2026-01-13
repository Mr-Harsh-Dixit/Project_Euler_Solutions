public class Main {
    public static void main(String[] args) {
        final int n = 10001;
        final int limit = 200000;

        boolean[] isPrime = new boolean[limit + 1];
        for (int i = 2; i <= limit; i++) isPrime[i] = true;

        for (int p = 2; p * p <= limit; p++) {
            if (isPrime[p]) {
                for (int x = p * p; x <= limit; x += p) {
                    isPrime[x] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                count++;
                if (count == n) {
                    System.out.println(i); // 104743
                    return;
                }
            }
        }
    }
}
