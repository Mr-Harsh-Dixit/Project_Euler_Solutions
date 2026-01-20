public class Main {

    static boolean isPandigital9(String s) {
        if (s.length() != 9) return false;
        boolean[] seen = new boolean[10];
        for (int i = 0; i < 9; i++) {
            int d = s.charAt(i) - '0';
            if (d == 0 || seen[d]) return false;
            seen[d] = true;
        }
        return true;
    }

    public static void main(String[] args) {
        int best = 0;

        for (int x = 9876; x >= 9123; x--) {
            String s = Integer.toString(x) + Integer.toString(2 * x);
            if (isPandigital9(s)) {
                best = Integer.parseInt(s);
                break;
            }
        }

        System.out.println(best); // 932718654
    }
}
