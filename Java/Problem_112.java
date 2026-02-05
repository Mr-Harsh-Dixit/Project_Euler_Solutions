public class Main {
    static boolean isBouncy(int n) {
        boolean inc = true, dec = true;
        int last = n % 10;
        n /= 10;

        while (n > 0) {
            int d = n % 10;
            if (d < last) inc = false;
            if (d > last) dec = false;
            last = d;
            n /= 10;

            if (!inc && !dec) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        int bouncy = 0;
        int n = 1;

        while (true) {
            n++;
            if (n >= 100 && isBouncy(n)) bouncy++;
            if ((long)bouncy * 100 == (long)n * 99) {
                System.out.println(n); // 1587000
                return;
            }
        }
    }
}
