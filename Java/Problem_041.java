public class Main {

    static boolean isPrime(int n) {
        if (n < 2) return false;
        if (n % 2 == 0) return n == 2;
        for (int f = 3; (long)f * f <= n; f += 2) {
            if (n % f == 0) return false;
        }
        return true;
    }

    static boolean prevPermutation(char[] a) {
        int i = a.length - 2;
        while (i >= 0 && a[i] <= a[i + 1]) i--;
        if (i < 0) return false;

        int j = a.length - 1;
        while (a[j] >= a[i]) j--;

        char tmp = a[i]; a[i] = a[j]; a[j] = tmp;

        int l = i + 1, r = a.length - 1;
        while (l < r) {
            tmp = a[l]; a[l] = a[r]; a[r] = tmp;
            l++; r--;
        }
        return true;
    }

    public static void main(String[] args) {
        char[] s = "7654321".toCharArray();

        while (true) {
            int num = 0;
            for (char c : s) num = num * 10 + (c - '0');
            if (isPrime(num)) {
                System.out.println(num); // 7652413
                return;
            }
            if (!prevPermutation(s)) break;
        }
    }
}
