import java.util.*;

public class Main {

    static boolean[] sieve(int limit) {
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; (long)p * p <= limit; p++) {
            if (isPrime[p]) {
                for (long x = (long)p * p; x <= limit; x += p) {
                    isPrime[(int)x] = false;
                }
            }
        }
        return isPrime;
    }

    static String signature(int n) {
        char[] a = Integer.toString(n).toCharArray();
        Arrays.sort(a);
        return new String(a);
    }

    public static void main(String[] args) {
        boolean[] isPrime = sieve(9999);

        HashMap<String, ArrayList<Integer>> groups = new HashMap<>();
        for (int p = 1000; p <= 9999; p++) {
            if (isPrime[p]) {
                String sig = signature(p);
                groups.computeIfAbsent(sig, k -> new ArrayList<>()).add(p);
            }
        }

        for (Map.Entry<String, ArrayList<Integer>> e : groups.entrySet()) {
            ArrayList<Integer> arr = e.getValue();
            if (arr.size() < 3) continue;

            Collections.sort(arr);
            HashSet<Integer> set = new HashSet<>(arr);

            for (int i = 0; i < arr.size(); i++) {
                for (int j = i + 1; j < arr.size(); j++) {
                    int a = arr.get(i), b = arr.get(j);
                    int c = 2 * b - a;
                    if (set.contains(c)) {
                        if (a == 1487 && b == 4817) continue;
                        System.out.println("" + a + b + c); // 296962999629
                        return;
                    }
                }
            }
        }
    }
}
