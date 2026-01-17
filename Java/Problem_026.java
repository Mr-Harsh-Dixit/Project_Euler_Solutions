import java.util.Arrays;

public class Main {

    static int cycleLength(int d) {
        while (d % 2 == 0) d /= 2;
        while (d % 5 == 0) d /= 5;
        if (d == 1) return 0;

        int[] seen = new int[d];
        Arrays.fill(seen, -1);

        int r = 1 % d;
        int pos = 0;

        while (seen[r] == -1) {
            seen[r] = pos;
            r = (r * 10) % d;
            pos++;
        }
        return pos - seen[r];
    }

    public static void main(String[] args) {
        int bestD = 0, bestLen = 0;

        for (int d = 2; d < 1000; d++) {
            int len = cycleLength(d);
            if (len > bestLen) {
                bestLen = len;
                bestD = d;
            }
        }

        System.out.println(bestD); // 983
    }
}
