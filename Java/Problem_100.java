public class Euler100 {
    public static void main(String[] args) {
        final long LIMIT = 1_000_000_000_000L;

        long x = 41, y = 29; // n=21, b=15

        while ((x + 1) / 2 <= LIMIT) {
            long xNew = 3*x + 4*y;
            long yNew = 2*x + 3*y;
            x = xNew;
            y = yNew;
        }

        long b = (y + 1) / 2;
        System.out.println(b); // 756872327473
    }
}
