import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> all = new ArrayList<>();
        ArrayList<Integer> finish = new ArrayList<>();

        for (int v = 1; v <= 20; v++) {
            all.add(v);         // S
            all.add(2*v);      // D
            all.add(3*v);      // T
            finish.add(2*v);   // D only
        }

        all.add(25);   // outer bull
        all.add(50);   // inner bull
        finish.add(50);

        Collections.sort(all);

        int ans = 0;

        for (int f : finish) {
            if (f < 100) ans++;

            for (int i = 0; i < all.size(); i++) {
                int a = all.get(i);
                if (a + f < 100) ans++;
                else continue;

                for (int j = i; j < all.size(); j++) {
                    int b = all.get(j);
                    if (a + b + f < 100) ans++;
                }
            }
        }

        System.out.println(ans); // 38182
    }
}
