import java.io.*;
import java.util.*;

public class Euler54 {
    static int rval(char c) {
        if (c >= '2' && c <= '9') return c - '0';
        switch (c) {
            case 'T': return 10;
            case 'J': return 11;
            case 'Q': return 12;
            case 'K': return 13;
            default:  return 14; // A
        }
    }

    static int[] score(String[] hand) {
        int[] ranks = new int[5];
        char[] suits = new char[5];
        for (int i = 0; i < 5; i++) {
            ranks[i] = rval(hand[i].charAt(0));
            suits[i] = hand[i].charAt(1);
        }
        Arrays.sort(ranks);

        boolean isFlush = true;
        for (int i = 1; i < 5; i++) if (suits[i] != suits[0]) { isFlush = false; break; }

        boolean isStraight = true;
        for (int i = 1; i < 5; i++) if (ranks[i] != ranks[i-1] + 1) { isStraight = false; break; }
        int straightHigh = ranks[4];
        if (!isStraight && ranks[0] == 2 && ranks[1] == 3 && ranks[2] == 4 && ranks[3] == 5 && ranks[4] == 14) {
            isStraight = true;
            straightHigh = 5;
        }

        int[] freq = new int[15];
        for (int r : ranks) freq[r]++;

        // groups: (count, rank)
        List<int[]> groups = new ArrayList<>();
        for (int r = 2; r <= 14; r++) {
            if (freq[r] > 0) groups.add(new int[]{freq[r], r});
        }
        groups.sort((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(b[0], a[0]);
            return Integer.compare(b[1], a[1]);
        });

        int[] ranksDesc = new int[]{ranks[4], ranks[3], ranks[2], ranks[1], ranks[0]};

        if (isFlush && isStraight) {
            if (straightHigh == 14) return new int[]{9};
            return new int[]{8, straightHigh};
        }

        if (groups.get(0)[0] == 4) {
            int quad = groups.get(0)[1];
            int kicker = 0;
            for (int r : ranks) if (r != quad) kicker = Math.max(kicker, r);
            return new int[]{7, quad, kicker};
        }

        if (groups.get(0)[0] == 3 && groups.size() > 1 && groups.get(1)[0] == 2) {
            return new int[]{6, groups.get(0)[1], groups.get(1)[1]};
        }

        if (isFlush) {
            int[] out = new int[1 + 5];
            out[0] = 5;
            System.arraycopy(ranksDesc, 0, out, 1, 5);
            return out;
        }

        if (isStraight) return new int[]{4, straightHigh};

        if (groups.get(0)[0] == 3) {
            int trip = groups.get(0)[1];
            int[] kicks = new int[2];
            int idx = 0;
            for (int i = 4; i >= 0; i--) if (ranks[i] != trip) kicks[idx++] = ranks[i];
            return new int[]{3, trip, kicks[0], kicks[1]};
        }

        if (groups.get(0)[0] == 2 && groups.size() > 1 && groups.get(1)[0] == 2) {
            int p1 = groups.get(0)[1], p2 = groups.get(1)[1];
            int highPair = Math.max(p1, p2), lowPair = Math.min(p1, p2);
            int kicker = 0;
            for (int r : ranks) if (r != p1 && r != p2) kicker = r;
            return new int[]{2, highPair, lowPair, kicker};
        }

        if (groups.get(0)[0] == 2) {
            int pair = groups.get(0)[1];
            int[] kicks = new int[3];
            int idx = 0;
            for (int i = 4; i >= 0; i--) if (ranks[i] != pair) kicks[idx++] = ranks[i];
            return new int[]{1, pair, kicks[0], kicks[1], kicks[2]};
        }

        int[] out = new int[1 + 5];
        out[0] = 0;
        System.arraycopy(ranksDesc, 0, out, 1, 5);
        return out;
    }

    static int cmp(int[] a, int[] b) {
        int m = Math.min(a.length, b.length);
        for (int i = 0; i < m; i++) {
            if (a[i] != b[i]) return Integer.compare(a[i], b[i]);
        }
        return Integer.compare(a.length, b.length);
    }

    static int solve(String path) throws IOException {
        int wins = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] cards = line.trim().split("\\s+");
                String[] h1 = Arrays.copyOfRange(cards, 0, 5);
                String[] h2 = Arrays.copyOfRange(cards, 5, 10);
                if (cmp(score(h1), score(h2)) > 0) wins++;
            }
        }
        return wins;
    }

    public static void main(String[] args) throws Exception {
        System.out.println(solve("poker.txt")); // should print 376 with official file
    }
}
