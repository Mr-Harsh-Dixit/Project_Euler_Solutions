import java.util.*;

public class Euler57 {

    static ArrayList<Integer> addDigits(List<Integer> a, List<Integer> b) {
        int n = Math.max(a.size(), b.size());
        ArrayList<Integer> out = new ArrayList<>(n + 2);
        int carry = 0;

        for (int i = 0; i < n; i++) {
            int da = (i < a.size()) ? a.get(i) : 0;
            int db = (i < b.size()) ? b.get(i) : 0;
            int s = da + db + carry;
            out.add(s % 10);
            carry = s / 10;
        }
        while (carry > 0) {
            out.add(carry % 10);
            carry /= 10;
        }
        return out;
    }

    static ArrayList<Integer> addScaledDigits(List<Integer> a, List<Integer> b, int k) {
        int n = Math.max(a.size(), b.size());
        ArrayList<Integer> out = new ArrayList<>(n + 3);
        int carry = 0;

        for (int i = 0; i < n; i++) {
            int da = (i < a.size()) ? a.get(i) : 0;
            int db = (i < b.size()) ? b.get(i) : 0;
            int s = da + k * db + carry;
            out.add(s % 10);
            carry = s / 10;
        }
        while (carry > 0) {
            out.add(carry % 10);
            carry /= 10;
        }
        return out;
    }

    static int solve() {
        ArrayList<Integer> p = new ArrayList<>();
        ArrayList<Integer> q = new ArrayList<>();
        p.add(3); // 3
        q.add(2); // 2

        int count = 0;

        for (int i = 0; i < 1000; i++) {
            if (p.size() > q.size()) count++;

            ArrayList<Integer> newP = addScaledDigits(p, q, 2); // p + 2q
            ArrayList<Integer> newQ = addDigits(p, q);          // p + q
            p = newP;
            q = newQ;
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(solve()); // 153
    }
}
