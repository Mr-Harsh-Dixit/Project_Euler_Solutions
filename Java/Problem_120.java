public class Main {
    public static void main(String[] args) {
        long total = 0;
        for (long a = 3; a <= 1000; a++) {
            if ((a & 1) == 1) total += a*a - a;
            else              total += a*a - 2*a;
        }
        System.out.println(total); // 333082500
    }
}
