import java.io.*;
import java.util.*;

public class Euler98 {
    static int[] patternKey(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int[] out = new int[s.length()];
        int nxt = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            Integer id = mp.get(ch);
            if (id == null) {
                id = nxt++;
                mp.put(ch, id);
            }
            out[i] = id;
        }
        return out;
    }

    static boolean samePattern(int[] a, int[] b) {
        if (a.length != b.length) return false;
        for (int i = 0; i < a.length; i++) if (a[i] != b[i]) return false;
        return true;
    }

    static boolean buildMap(String word, String num, char[] l2d, char[] d2l) {
        Arrays.fill(l2d, (char)0);
        Arrays.fill(d2l, (char)0);
        for (int i = 0; i < word.length(); i++) {
            int li = word.charAt(i) - 'A';
            int di = num.charAt(i) - '0';
            char needD = num.charAt(i);

            if (l2d[li] != 0 && l2d[li] != needD) return false;
            if (d2l[di] != 0 && d2l[di] != word.charAt(i)) return false;

            l2d[li] = needD;
            d2l[di] = word.charAt(i);
        }
        return l2d[word.charAt(0) - 'A'] != '0';
    }

    static String applyMap(String word, char[] l2d) {
        char[] out = new char[word.length()];
        for (int i = 0; i < word.length(); i++) {
            out[i] = l2d[word.charAt(i) - 'A'];
        }
        return new String(out);
    }

    static void ensureSquares(int L,
                              Map<Integer, List<String>> squaresList,
                              Map<Integer, HashSet<String>> squaresSet) {
        if (squaresList.containsKey(L)) return;

        long lo = 1;
        for (int i = 1; i < L; i++) lo *= 10;
        long hi = lo * 10 - 1;

        long a = (long)Math.sqrt(lo);
        while (a * a < lo) a++;
        long b = (long)Math.sqrt(hi);

        ArrayList<String> lst = new ArrayList<>();
        HashSet<String> st = new HashSet<>();
        for (long x = a; x <= b; x++) {
            long sq = x * x;
            String s = Long.toString(sq);
            lst.add(s);
            st.add(s);
        }
        squaresList.put(L, lst);
        squaresSet.put(L, st);
    }

    public static void main(String[] args) throws Exception {
        // Read the single-line CSV words file
        BufferedReader br = new BufferedReader(new FileReader("words.txt"));
        String raw = br.readLine();
        br.close();

        String[] parts = raw.replace("\"", "").split(",");
        ArrayList<String> words = new ArrayList<>(Arrays.asList(parts));

        // Group anagrams by sorted signature
        HashMap<String, ArrayList<String>> groups = new HashMap<>();
        for (String w : words) {
            char[] arr = w.toCharArray();
            Arrays.sort(arr);
            String sig = new String(arr);
            groups.computeIfAbsent(sig, k -> new ArrayList<>()).add(w);
        }

        Map<Integer, List<String>> squaresList = new HashMap<>();
        Map<Integer, HashSet<String>> squaresSet = new HashMap<>();

        long best = 0;
        char[] l2d = new char[26];
        char[] d2l = new char[10];

        for (ArrayList<String> ws : groups.values()) {
            if (ws.size() < 2) continue;

            for (int i = 0; i < ws.size(); i++) {
                for (int j = i + 1; j < ws.size(); j++) {
                    String a = ws.get(i);
                    String b = ws.get(j);
                    int L = a.length();
                    if (b.length() != L) continue;

                    ensureSquares(L, squaresList, squaresSet);

                    int[] pa = patternKey(a);
                    int[] pb = patternKey(b);

                    for (String sq : squaresList.get(L)) {
                        if (!samePattern(patternKey(sq), pa)) continue;
                        if (!buildMap(a, sq, l2d, d2l)) continue;

                        String other = applyMap(b, l2d);
                        if (other.charAt(0) == '0') continue;

                        if (squaresSet.get(L).contains(other) &&
                            samePattern(patternKey(other), pb)) {
                            best = Math.max(best, Long.parseLong(sq));
                            best = Math.max(best, Long.parseLong(other));
                        }
                    }
                }
            }
        }

        System.out.println(best); // 18769
    }
}
