import java.util.*;

public class Euler84 {
    static int toId(int pos, int d) { return pos * 3 + d; }

    static boolean isCC(int p) { return p==2 || p==17 || p==33; }
    static boolean isCH(int p) { return p==7 || p==22 || p==36; }

    static int nextR(int pos) {
        int[] R = {5, 15, 25, 35};
        for (int r : R) if (r > pos) return r;
        return R[0];
    }

    static int nextU(int pos) {
        int[] U = {12, 28};
        for (int u : U) if (u > pos) return u;
        return U[0];
    }

    static List<int[]> resolvePos(int pos) {
        // returns list of {finalPos, numeratorProb} with denominator 16 for CC/CH
        // We'll carry probabilities as doubles anyway in caller.
        throw new RuntimeException("Use the full version below.");
    }

    public static void main(String[] args) {
        final int N = 40, SIDES = 4, ST = 120;
        final int JAIL = 10, G2J = 30;
        final double pDie = 1.0 / (SIDES * SIDES);

        // resolve(pos) -> list of (finalPos, prob)
        class Resolver {
            List<long[]> resolve(int pos) {
                if (pos == G2J) return List.of(new long[]{JAIL, Double.doubleToLongBits(1.0)});
                if (isCC(pos)) {
                    return List.of(
                        new long[]{0,    Double.doubleToLongBits(1.0/16.0)},
                        new long[]{JAIL, Double.doubleToLongBits(1.0/16.0)},
                        new long[]{pos,  Double.doubleToLongBits(14.0/16.0)}
                    );
                }
                if (isCH(pos)) {
                    ArrayList<long[]> out = new ArrayList<>();
                    out.add(new long[]{0,  Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{JAIL,Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{11, Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{24, Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{39, Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{5,  Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{nextR(pos), Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{nextR(pos), Double.doubleToLongBits(1.0/16.0)});
                    out.add(new long[]{nextU(pos), Double.doubleToLongBits(1.0/16.0)});

                    int back3 = (pos - 3 + N) % N;
                    if (isCC(back3)) {
                        for (long[] e : resolve(back3)) {
                            int fp = (int)e[0];
                            double pr = Double.longBitsToDouble(e[1]);
                            out.add(new long[]{fp, Double.doubleToLongBits((1.0/16.0)*pr)});
                        }
                    } else {
                        out.add(new long[]{back3, Double.doubleToLongBits(1.0/16.0)});
                    }

                    out.add(new long[]{pos, Double.doubleToLongBits(6.0/16.0)});
                    return out;
                }
                return List.of(new long[]{pos, Double.doubleToLongBits(1.0)});
            }
        }

        Resolver resolver = new Resolver();

        // transitions: for each state, list of (nextState, prob)
        ArrayList<int[]> nextState = new ArrayList<>(ST);
        ArrayList<double[]> nextProb = new ArrayList<>(ST);
        for (int i = 0; i < ST; i++) { nextState.add(new int[0]); nextProb.add(new double[0]); }

        for (int pos = 0; pos < N; pos++) for (int d = 0; d < 3; d++) {
            int s = toId(pos, d);
            HashMap<Integer, Double> acc = new HashMap<>(64);

            for (int a = 1; a <= SIDES; a++) for (int b = 1; b <= SIDES; b++) {
                boolean dbl = (a == b);

                if (dbl && d == 2) {
                    acc.merge(toId(JAIL, 0), pDie, Double::sum);
                    continue;
                }

                int nd = dbl ? (d + 1) : 0;
                int np = (pos + a + b) % N;

                for (long[] e : resolver.resolve(np)) {
                    int fp = (int)e[0];
                    double pr = Double.longBitsToDouble(e[1]);
                    int fd = (fp == JAIL) ? 0 : nd;
                    int t = toId(fp, fd);
                    acc.merge(t, pDie * pr, Double::sum);
                }
            }

            int[] ts = new int[acc.size()];
            double[] ps = new double[acc.size()];
            int k = 0;
            for (var entry : acc.entrySet()) {
                ts[k] = entry.getKey();
                ps[k] = entry.getValue();
                k++;
            }
            nextState.set(s, ts);
            nextProb.set(s, ps);
        }

        // power iteration
        double[] v = new double[ST];
        Arrays.fill(v, 1.0 / ST);

        for (int it = 0; it < 3000; it++) {
            double[] v2 = new double[ST];
            for (int s = 0; s < ST; s++) {
                double vs = v[s];
                if (vs == 0.0) continue;
                int[] ts = nextState.get(s);
                double[] ps = nextProb.get(s);
                for (int k = 0; k < ts.length; k++) v2[ts[k]] += vs * ps[k];
            }
            double diff = 0.0;
            for (int i = 0; i < ST; i++) diff = Math.max(diff, Math.abs(v2[i] - v[i]));
            v = v2;
            if (diff < 1e-15) break;
        }

        double[] sq = new double[N];
        for (int pos = 0; pos < N; pos++) {
            sq[pos] = v[toId(pos,0)] + v[toId(pos,1)] + v[toId(pos,2)];
        }

        Integer[] idx = new Integer[N];
        for (int i = 0; i < N; i++) idx[i] = i;
        Arrays.sort(idx, (a,b) -> Double.compare(sq[b], sq[a]));

        System.out.printf("%02d%02d%02d%n", idx[0], idx[1], idx[2]); // 101524
    }
}
