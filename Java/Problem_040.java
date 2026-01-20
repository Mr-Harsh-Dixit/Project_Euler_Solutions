public class Main {

    static int digitAt(long k) { // 1-indexed
        long len = 1;
        long count = 9;
        long start = 1;

        while (k > len * count) {
            k -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        long index = (k - 1) / len;
        int offset = (int)((k - 1) % len);
        long num = start + index;

        String s = Long.toString(num);
        return s.charAt(offset) - '0';
    }

    public static void main(String[] args) {
        long[] pos = {1,10,100,1000,10000,100000,1000000};
        long ans = 1;

        for (long p : pos) ans *= digitAt(p);

        System.out.println(ans); // 210
    }
}
