public class Main {
    private static long sumMultiples(int k, int n) {
        long m = (n - 1) / k;
        return k * m * (m + 1) / 2;
    }

    public static void main(String[] args) {
        int n = 1000;
        long result = sumMultiples(3, n) + sumMultiples(5, n) - sumMultiples(15, n);
        System.out.println(result);  // Expected output: 233168
    }
}