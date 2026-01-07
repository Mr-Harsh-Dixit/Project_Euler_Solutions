public class Main {
    public static void main(String[] args) {
        long n = 600851475143L;
        long maxFactor = 1;

        while (n % 2 == 0) {
            maxFactor = 2;
            n /= 2;
        }

        for (long i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                maxFactor = i;
                n /= i;
            }
        }

        if (n > 1)
            maxFactor = n;

        System.out.println(maxFactor); // 6857
    }
}
