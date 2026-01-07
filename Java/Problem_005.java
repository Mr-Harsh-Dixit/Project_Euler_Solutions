public class Main {

    private static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    public static void main(String[] args) {
        long result = 1;
        for (int i = 2; i <= 20; i++) {
            result = lcm(result, i);
        }
        System.out.println(result); // 232792560
    }
}
