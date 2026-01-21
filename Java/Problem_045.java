public class Main {

    static boolean isPent(long x) {
        long disc = 1L + 24L * x;
        long s = (long)Math.sqrt(disc);
        while (s * s < disc) s++;
        while (s * s > disc) s--;
        return s * s == disc && (1 + s) % 6 == 0;
    }

    public static void main(String[] args) {
        long n = 144;
        while (true) {
            long h = n * (2L * n - 1); // hexagonal
            if (isPent(h)) {
                System.out.println(h); // 1533776805
                break;
            }
            n++;
        }
    }
}
