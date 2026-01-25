public class Euler63 {
    public static void main(String[] args) {
        int total = 0;

        for (int n = 1; ; n++) {
            for (int a = 1; a <= 9; a++) {
                int digits = (int)Math.floor(n * Math.log10(a)) + 1;
                if (digits == n) total++;
            }
            int maxDigits = (int)Math.floor(n * Math.log10(9)) + 1;
            if (maxDigits < n) break;
        }

        System.out.println(total); // 49
    }
}
