import java.util.*;

public class Euler93 {
    static class Frac {
        long n, d; // reduced, d>0
        Frac(long n, long d) {
            if (d == 0) throw new ArithmeticException("div0");
            if (d < 0) { n = -n; d = -d; }
            long g = gcd(Math.abs(n), d);
            this.n = n / g;
            this.d = d / g;
        }
        static long gcd(long a, long b) {
            while (b != 0) { long t = a % b; a = b; b = t; }
            return a;
        }
        @Override public int hashCode() {
            return Objects.hash(n, d);
        }
        @Override public boolean equals(Object o) {
            if (!(o instanceof Frac)) return false;
            Frac f = (Frac)o;
            return n == f.n && d == f.d;
        }
    }

    static Frac add(Frac a, Frac b){ return new Frac(a.n*b.d + b.n*a.d, a.d*b.d); }
    static Frac sub(Frac a, Frac b){ return new Frac(a.n*b.d - b.n*a.d, a.d*b.d); }
    static Frac mul(Frac a, Frac b){ return new Frac(a.n*b.n, a.d*b.d); }
    static Frac div(Frac a, Frac b){
        if (b.n == 0) throw new ArithmeticException("div0");
        return new Frac(a.n*b.d, a.d*b.n);
    }

    static HashSet<Frac> allValues(ArrayList<Frac> nums) {
        if (nums.size() == 1) {
            HashSet<Frac> base = new HashSet<>();
            base.add(nums.get(0));
            return base;
        }

        HashSet<Frac> out = new HashSet<>();
        int L = nums.size();

        for (int i=0;i<L;i++){
            for (int j=i+1;j<L;j++){
                Frac a = nums.get(i), b = nums.get(j);

                ArrayList<Frac> rest = new ArrayList<>(L-1);
                for (int k=0;k<L;k++) if (k!=i && k!=j) rest.add(nums.get(k));

                java.util.function.Consumer<Frac> merge = (Frac v) -> {
                    ArrayList<Frac> next = new ArrayList<>(rest);
                    next.add(v);
                    out.addAll(allValues(next));
                };

                merge.accept(add(a,b));
                merge.accept(mul(a,b));
                merge.accept(sub(a,b));
                merge.accept(sub(b,a));
                if (b.n != 0) merge.accept(div(a,b));
                if (a.n != 0) merge.accept(div(b,a));
            }
        }
        return out;
    }

    public static void main(String[] args) {
        int bestLen = 0;
        int ba=0, bb=0, bc=0, bd=0;

        for (int a=1;a<=6;a++){
            for (int b=a+1;b<=7;b++){
                for (int c=b+1;c<=8;c++){
                    for (int d=c+1;d<=9;d++){
                        ArrayList<Frac> start = new ArrayList<>();
                        start.add(new Frac(a,1));
                        start.add(new Frac(b,1));
                        start.add(new Frac(c,1));
                        start.add(new Frac(d,1));

                        HashSet<Frac> vals = allValues(start);

                        HashSet<Integer> ints = new HashSet<>();
                        for (Frac v : vals) {
                            if (v.d == 1 && v.n > 0 && v.n <= Integer.MAX_VALUE) {
                                ints.add((int)v.n);
                            }
                        }

                        int n = 1;
                        while (ints.contains(n)) n++;
                        int runLen = n - 1;

                        if (runLen > bestLen) {
                            bestLen = runLen;
                            ba=a; bb=b; bc=c; bd=d;
                        }
                    }
                }
            }
        }

        System.out.println("" + ba + bb + bc + bd); // 1258
    }
}
