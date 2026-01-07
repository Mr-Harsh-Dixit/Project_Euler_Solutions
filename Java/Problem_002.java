public class Main {
    public static void main(String[] args) {
        final long limit = 4_000_000L;
        long total = 0;
        long a = 2, b = 8;

        while (a <= limit) {
            total += a;
            long next = 4 * b + a;
            a = b;
            b = next;
        }

        System.out.println(total); // 4613732
    }
}
