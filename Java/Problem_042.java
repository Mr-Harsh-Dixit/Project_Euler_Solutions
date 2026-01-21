import java.nio.file.*;
import java.util.*;

public class Main {

    static int wordValue(String w) {
        int sum = 0;
        for (int i = 0; i < w.length(); i++) {
            sum += (w.charAt(i) - 'A' + 1);
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        String data = Files.readString(Path.of("words.txt")).trim();
        String[] raw = data.split(",");

        int[] vals = new int[raw.length];
        int maxVal = 0;

        for (int i = 0; i < raw.length; i++) {
            String w = raw[i].replace("\"", "");
            int v = wordValue(w);
            vals[i] = v;
            if (v > maxVal) maxVal = v;
        }

        HashSet<Integer> tri = new HashSet<>();
        for (int n = 1;; n++) {
            int t = n * (n + 1) / 2;
            if (t > maxVal) break;
            tri.add(t);
        }

        int count = 0;
        for (int v : vals) if (tri.contains(v)) count++;

        System.out.println(count); // 162 for Project Euler words.txt
    }
}
