import java.util.ArrayList;

public class Euler56 {

    static void multiplyDigits(ArrayList<Integer> digits, int m) {
        int carry = 0;
        for (int i = 0; i < digits.size(); i++) {
            int prod = digits.get(i) * m + carry;
            digits.set(i, prod % 10);
            carry = prod / 10;
        }
        while (carry > 0) {
            digits.add(carry % 10);
            carry /= 10;
        }
    }

    static int digitSum(ArrayList<Integer> digits) {
        int s = 0;
        for (int d : digits) s += d;
        return s;
    }

    static int solve() {
        int best = 0;
        for (int a = 1; a < 100; a++) {
            for (int b = 1; b < 100; b++) {
                ArrayList<Integer> digits = new ArrayList<>();
                digits.add(1);
                for (int i = 0; i < b; i++) multiplyDigits(digits, a);
                best = Math.max(best, digitSum(digits));
            }
        }
        return best;
    }

    public static void main(String[] args) {
        System.out.println(solve()); // 972
    }
}
