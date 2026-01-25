import java.util.*;

public class Euler62 {
    static class Info {
        int count;
        long smallest;
        Info(int c, long s) { count = c; smallest = s; }
    }

    static String signature(long x) {
        char[] ch = Long.toString(x).toCharArray();
        Arrays.sort(ch);
        return new String(ch);
    }

    public static void main(String[] args) {
        for (int digitsLen = 1; ; digitsLen++) {
            HashMap<String, Info> seen = new HashMap<>(200000);

            long n = 1;
            while (Long.toString(n*n*n).length() < digitsLen) n++;

            while (true) {
                long c = n*n*n;
                String s = Long.toString(c);
                if (s.length() > digitsLen) break;

                String sig = signature(c);
                Info info = seen.get(sig);
                if (info == null) {
                    seen.put(sig, new Info(1, c)); // first is smallest
                } else {
                    info.count++;
                }
                n++;
            }

            long best = -1;
            for (Info info : seen.values()) {
                if (info.count == 5) {
                    if (best == -1 || info.smallest < best) best = info.smallest;
                }
            }

            if (best != -1) {
                System.out.println(best); // 127035954683
                return;
            }
        }
    }
}
