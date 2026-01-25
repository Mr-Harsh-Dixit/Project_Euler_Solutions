import java.util.*;

public class Euler65 {

    // digits LSB first
    static ArrayList<Integer> add(List<Integer> a, List<Integer> b) {
        ArrayList<Integer> r = new ArrayList<>();
        int carry = 0;
        int n = Math.max(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            int da = i < a.size() ? a.get(i) : 0;
            int db = i < b.size() ? b.get(i) : 0;
            int s = da + db + carry;
            r.add(s % 10);
            carry = s / 10;
        }
        while (carry > 0) {
            r.add(carry % 10);
            carry /= 10;
        }
        return r;
    }

    static ArrayList<Integer> mulSmall(List<Integer> a, int m) {
        ArrayList<Integer> r = new ArrayList<>();
        int carry = 0;
        for (int d : a) {
            int s = d * m + carry;
            r.add(s % 10);
            carry = s / 10;
        }
        while (carry > 0) {
            r.add(carry % 10);
            carry /= 10;
        }
        return r;
    }

    public static void main(String[] args) {
        int[] a = new int[100];
        a[0] = 2;
        for (int i = 1; i < 100; i++) {
            if (i % 3 == 2) a[i] = 2 * ((i + 1) / 3);
            else a[i] = 1;
        }

        ArrayList<Integer> pprev = new ArrayList<>();
        pprev.add(0);
        ArrayList<Integer> pcurr = new ArrayList<>();
        pcurr.add(1);

        for (int i = 0; i < 100; i++) {
            ArrayList<Integer> term = mulSmall(pcurr, a[i]);
            ArrayList<Integer> pnext = add(term, pprev);
            pprev = pcurr;
            pcurr = pnext;
        }

        int sum = 0;
        for (int d : pcurr) sum += d;

        System.out.println(sum); // 272
    }
}
