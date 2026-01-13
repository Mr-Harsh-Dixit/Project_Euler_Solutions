public class Main {
    public static void main(String[] args) {
        long n = 100;
        long sum = n * (n + 1) / 2;
        long sumSquares = n * (n + 1) * (2 * n + 1) / 6;

        System.out.println(sum * sum - sumSquares); // 25164150
    }
}
