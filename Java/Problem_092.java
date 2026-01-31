public class Euler92 {
    static int nextSum(int n, int[] digitSq) {
        int s = 0;
        while (n != 0) {
            s += digitSq[n % 10];
            n /= 10;
        }
        return s;
    }

    static void resolve(int start, int[] fate, int[] digitSq) {
        int s = start;
        int[] path = new int[32]; // chains are short
        int len = 0;

        while (fate[s] == 0) {
            path[len++] = s;
            s = nextSum(s, digitSq);
        }
        int end = fate[s];
        for (int i = 0; i < len; i++) fate[path[i]] = end;
    }

    public static void main(String[] args) {
        final int LIMIT = 10_000_000;
        final int MAXS = 567;

        int[] digitSq = new int[10];
        for (int i = 0; i < 10; i++) digitSq[i] = i * i;

        int[] fate = new int[MAXS + 1];
        fate[1] = 1;
        fate[89] = 89;

        for (int s = 1; s <= MAXS; s++) {
            if (fate[s] == 0) resolve(s, fate, digitSq);
        }

        int count = 0;
        for (int n = 1; n < LIMIT; n++) {
            int s = nextSum(n, digitSq);
            if (fate[s] == 89) count++;
        }

        System.out.println(count); // 8581146
    }
}
