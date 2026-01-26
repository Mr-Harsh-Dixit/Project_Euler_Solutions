import java.util.*;

public class Euler66 {

    static class Big {
        static final int BASE = 1_000_000_000;
        ArrayList<Integer> d = new ArrayList<>(); // little-endian

        Big(long x) {
            if (x == 0) d.add(0);
            else while (x > 0) { d.add((int)(x % BASE)); x /= BASE; }
        }

        void trim() {
            while (d.size() > 1 && d.get(d.size() - 1) == 0) d.remove(d.size() - 1);
        }
    }

    static int cmp(Big a, Big b) {
        if (a.d.size() != b.d.size()) return Integer.compare(a.d.size(), b.d.size());
        for (int i = a.d.size() - 1; i >= 0; i--) {
            int ai = a.d.get(i), bi = b.d.get(i);
            if (ai != bi) return Integer.compare(ai, bi);
        }
        return 0;
    }

    static Big add(Big a, Big b) {
        Big r = new Big(0);
        r.d.clear();
        int n = Math.max(a.d.size(), b.d.size());
        long carry = 0;
        for (int i = 0; i < n; i++) {
            long s = carry;
            if (i < a.d.size()) s += a.d.get(i);
            if (i < b.d.size()) s += b.d.get(i);
            r.d.add((int)(s % Big.BASE));
            carry = s / Big.BASE;
        }
        if (carry > 0) r.d.add((int)carry);
        r.trim();
        return r;
    }

    static Big mulSmall(Big a, long m) {
        Big r = new Big(0);
        r.d.clear();
        long carry = 0;
        for (int i = 0; i < a.d.size(); i++) {
            long cur = carry + 1L * a.d.get(i) * m;
            r.d.add((int)(cur % Big.BASE));
            carry = cur / Big.BASE;
        }
        while (carry > 0) {
            r.d.add((int)(carry % Big.BASE));
            carry /= Big.BASE;
        }
        r.trim();
        return r;
    }

    static Big mul(Big a, Big b) {
        Big r = new Big(0);
        r.d = new ArrayList<>(Collections.nCopies(a.d.size() + b.d.size(), 0));

        for (int i = 0; i < a.d.size(); i++) {
            long carry = 0;
            for (int j = 0; j < b.d.size() || carry > 0; j++) {
                long cur = r.d.get(i + j) + carry;
                if (j < b.d.size()) cur += 1L * a.d.get(i) * b.d.get(j);
                r.d.set(i + j, (int)(cur % Big.BASE));
                carry = cur / Big.BASE;
            }
        }
        r.trim();
        return r;
    }

    static Big sub(Big a, Big b) {
        // assume a >= b
        Big r = new Big(0);
        r.d.clear();
        r.d.addAll(a.d);

        long borrow = 0;
        for (int i = 0; i < r.d.size(); i++) {
            long cur = (long)r.d.get(i) - borrow - (i < b.d.size() ? b.d.get(i) : 0);
            if (cur < 0) { cur += Big.BASE; borrow = 1; }
            else borrow = 0;
            r.d.set(i, (int)cur);
        }
        r.trim();
        return r;
    }

    static Big minimalX(int D) {
        int a0 = (int)Math.sqrt(D);
        long m = 0, d = 1, a = a0;

        Big p_m2 = new Big(0), p_m1 = new Big(1);
        Big q_m2 = new Big(1), q_m1 = new Big(0);

        while (true) {
            Big p = add(mulSmall(p_m1, a), p_m2);
            Big q = add(mulSmall(q_m1, a), q_m2);

            Big p2 = mul(p, p);
            Big q2 = mul(q, q);
            Big Dq2 = mulSmall(q2, D);
            Big diff = sub(p2, Dq2);

            if (diff.d.size() == 1 && diff.d.get(0) == 1) return p;

            p_m2 = p_m1; p_m1 = p;
            q_m2 = q_m1; q_m1 = q;

            m = d * a - m;
            d = (D - m * m) / d;
            a = (a0 + m) / d;
        }
    }

    public static void main(String[] args) {
        int bestD = 0;
        Big bestX = new Big(0);

        for (int D = 2; D <= 1000; D++) {
            int a0 = (int)Math.sqrt(D);
            if ((long)a0 * a0 == D) continue;

            Big x = minimalX(D);
            if (cmp(x, bestX) > 0) {
                bestX = x;
                bestD = D;
            }
        }

        System.out.println(bestD); // 661
    }
}
