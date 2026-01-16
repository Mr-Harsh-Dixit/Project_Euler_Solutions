import java.nio.file.*;
import java.util.*;

public class Main {

    static int nameValue(String name) {
        int sum = 0;
        for (int i = 0; i < name.length(); i++) {
            sum += name.charAt(i) - 'A' + 1;
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        String content = Files.readString(Path.of("names.txt")).trim();
        String[] raw = content.split(",");

        ArrayList<String> names = new ArrayList<>(raw.length);
        for (String s : raw) {
            names.add(s.replace("\"", ""));
        }

        Collections.sort(names);

        long total = 0;
        for (int i = 0; i < names.size(); i++) {
            total += (long)(i + 1) * nameValue(names.get(i));
        }

        System.out.println(total); // 871198282
    }
}
