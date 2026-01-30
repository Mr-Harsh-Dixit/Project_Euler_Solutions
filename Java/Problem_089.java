import java.io.*;
import java.util.*;

public class Euler89 {

    static int romanToInt(String s) {
        Map<Character,Integer> v = Map.of(
            'I',1,'V',5,'X',10,'L',50,
            'C',100,'D',500,'M',1000
        );
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i+1 < s.length() && v.get(s.charAt(i)) < v.get(s.charAt(i+1)))
                total -= v.get(s.charAt(i));
            else
                total += v.get(s.charAt(i));
        }
        return total;
    }

    static String intToRoman(int n) {
        int[] vals = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < vals.length; i++) {
            while (n >= vals[i]) {
                sb.append(sym[i]);
                n -= vals[i];
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("roman.txt"));
        String line;
        long saved = 0;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            int v = romanToInt(line);
            String m = intToRoman(v);
            saved += line.length() - m.length();
        }

        System.out.println(saved); // 743
    }
}
