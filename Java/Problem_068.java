public class Euler68 {
    public static void main(String[] args) {
        String best = "";

        for (int a = 1; a <= 10; a++)
        for (int b = 1; b <= 10; b++) if (b != a)
        for (int c = 1; c <= 10; c++) if (c != a && c != b)
        for (int d = 1; d <= 10; d++) if (d != a && d != b && d != c)
        for (int e = 1; e <= 10; e++) if (e != a && e != b && e != c && e != d) {

            int[] I = {a,b,c,d,e};
            boolean has10 = (a==10||b==10||c==10||d==10||e==10);
            if (has10) continue;

            boolean[] inInner = new boolean[11];
            for (int v : I) inInner[v] = true;

            for (int E0 = 1; E0 <= 10; E0++) {
                if (inInner[E0]) continue;

                int S = E0 + I[0] + I[1];
                int[] E = new int[5];
                E[0] = E0;

                boolean[] usedE = new boolean[11];
                usedE[E0] = true;
                boolean ok = true;

                for (int k = 1; k < 5; k++) {
                    int ek = S - I[k] - I[(k+1)%5];
                    if (ek < 1 || ek > 10 || inInner[ek] || usedE[ek]) { ok = false; break; }
                    usedE[ek] = true;
                    E[k] = ek;
                }
                if (!ok) continue;
                if (!usedE[10]) continue;

                int[][] t = new int[5][3];
                for (int k = 0; k < 5; k++) {
                    t[k][0] = E[k];
                    t[k][1] = I[k];
                    t[k][2] = I[(k+1)%5];
                }

                int minIdx = 0;
                for (int k = 1; k < 5; k++) if (t[k][0] < t[minIdx][0]) minIdx = k;

                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < 5; k++) {
                    int[] tri = t[(minIdx + k) % 5];
                    sb.append(tri[0]).append(tri[1]).append(tri[2]);
                }

                String s = sb.toString();
                if (s.length() == 16 && s.compareTo(best) > 0) best = s;
            }
        }

        System.out.println(best); // 6531031914842725
    }
}
