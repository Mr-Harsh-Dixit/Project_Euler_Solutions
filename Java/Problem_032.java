import java.util.*;

public class Main {

    static boolean isPandigital(int a, int b, int p) {
        String s = "" + a + b + p;
        if (s.length() != 9) return false;

        boolean[] seen = new boolean[10];
        for (int i = 0; i < s.length(); i++) {
            int d = s.charAt(i) - '0';
            if (d == 0 || seen[d]) return false;
            seen[d] = true;
        }
        return true;
    }

    public static void main(String[] args) {
        HashSet<Integer> prods = new HashSet<>();

        for (int a = 1; a <= 9; a++) {
            for (int b = 1234; b <= 9876; b++) {
                int p = a * b;
                if (p >= 1000 && p <= 9999 && isPandigital(a, b, p)) {
                    prods.add(p);
                }
            }
        }

        for (int a = 12; a <= 98; a++) {
            for (int b = 123; b <= 987; b++) {
                int p = a * b;
                if (p >= 1000 && p <= 9999 && isPandigital(a, b, p)) {
                    prods.add(p);
                }
            }
        }

        long sum = 0;
        for (int x : prods) sum += x;

        System.out.println(sum); // 45228
    }
}
