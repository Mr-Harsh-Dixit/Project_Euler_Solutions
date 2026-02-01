import java.io.*;

public class Euler99 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("base_exp.txt"));

        int bestLine = -1;
        double bestScore = Double.NEGATIVE_INFINITY;

        String line;
        int i = 0;
        while ((line = br.readLine()) != null) {
            i++;
            int comma = line.indexOf(',');
            long b = Long.parseLong(line.substring(0, comma));
            long e = Long.parseLong(line.substring(comma + 1));

            double score = e * Math.log(b); // ln(b)
            if (score > bestScore) {
                bestScore = score;
                bestLine = i;
            }
        }
        br.close();

        System.out.println(bestLine); // 709 for Euler dataset
    }
}
