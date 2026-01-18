public class Main {

    static long gcd(long a, long b) {
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public static void main(String[] args) {
        long numProd = 1, denProd = 1;

        for (int n = 10; n < 100; n++) {
            for (int d = n + 1; d < 100; d++) {
                if (n % 10 == 0 && d % 10 == 0) continue; // trivial

                String ns = Integer.toString(n);
                String ds = Integer.toString(d);

                for (int i = 0; i < ns.length(); i++) {
                    char c = ns.charAt(i);
                    if (c == '0') continue;

                    int pos = ds.indexOf(c);
                    if (pos == -1) continue;

                    String n2s = ns.substring(0, i) + ns.substring(i + 1);
                    String d2s = ds.substring(0, pos) + ds.substring(pos + 1);

                    int n2 = Integer.parseInt(n2s);
                    int d2 = Integer.parseInt(d2s);

                    if (d2 != 0 && n * d2 == d * n2) {
                        numProd *= n;
                        denProd *= d;
                    }
                }
            }
        }

        long g = gcd(numProd, denProd);
        System.out.println(denProd / g); // 100
    }
}
