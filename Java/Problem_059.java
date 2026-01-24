import java.io.*;
import java.util.*;

public class Euler59 {

    static int[] readCipher(String path) throws IOException {
        String s;
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            s = br.readLine();
        }
        String[] parts = s.split(",");
        int[] arr = new int[parts.length];
        for (int i = 0; i < parts.length; i++) arr[i] = Integer.parseInt(parts[i].trim());
        return arr;
    }

    static boolean printable(int p) {
        return p == 10 || (p >= 32 && p <= 126);
    }

    static int scoreEnglish(String text) {
        String t = " " + text.toLowerCase() + " ";
        String[] common = {" the ", " and ", " of ", " to ", " in ", " that ", " is ", " was "};
        int score = 0;
        for (String w : common) {
            int idx = 0;
            while ((idx = t.indexOf(w, idx)) != -1) {
                score++;
                idx += 1;
            }
        }
        return score;
    }

    public static void main(String[] args) throws Exception {
        int[] cipher = readCipher("0059_cipher.txt");

        int bestScore = -1;
        String bestKey = "";
        String bestPlain = "";

        for (int a = 'a'; a <= 'z'; a++) {
            for (int b = 'a'; b <= 'z'; b++) {
                for (int c = 'a'; c <= 'z'; c++) {
                    int[] key = {a, b, c};
                    StringBuilder sb = new StringBuilder(cipher.length);
                    boolean ok = true;

                    for (int i = 0; i < cipher.length; i++) {
                        int p = cipher[i] ^ key[i % 3];
                        if (!printable(p)) { ok = false; break; }
                        sb.append((char)p);
                    }
                    if (!ok) continue;

                    String plain = sb.toString();
                    int sc = scoreEnglish(plain);
                    if (sc > bestScore) {
                        bestScore = sc;
                        bestKey = "" + (char)a + (char)b + (char)c;
                        bestPlain = plain;
                    }
                }
            }
        }

        long sum = 0;
        for (int i = 0; i < bestPlain.length(); i++) sum += (int)bestPlain.charAt(i);

        System.out.println(bestKey + " " + sum); // god 129448 (official file)
    }
}
