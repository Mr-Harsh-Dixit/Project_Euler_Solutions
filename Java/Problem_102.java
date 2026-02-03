import java.io.*;
import java.util.*;

public class Main {
    static long cross(long ax, long ay, long bx, long by) {
        return ax * by - ay * bx;
    }

    static boolean containsOrigin(long x1,long y1,long x2,long y2,long x3,long y3) {
        long s1 = cross(x2 - x1, y2 - y1, -x1, -y1);
        long s2 = cross(x3 - x2, y3 - y2, -x2, -y2);
        long s3 = cross(x1 - x3, y1 - y3, -x3, -y3);

        if (s1 == 0 || s2 == 0 || s3 == 0) return false; // strict interior

        boolean hasPos = (s1 > 0) || (s2 > 0) || (s3 > 0);
        boolean hasNeg = (s1 < 0) || (s2 < 0) || (s3 < 0);
        return !(hasPos && hasNeg);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("triangles.txt"));
        String line;
        int count = 0;

        while ((line = br.readLine()) != null) {
            String[] p = line.trim().split(",");
            if (p.length != 6) continue;

            long x1 = Long.parseLong(p[0]);
            long y1 = Long.parseLong(p[1]);
            long x2 = Long.parseLong(p[2]);
            long y2 = Long.parseLong(p[3]);
            long x3 = Long.parseLong(p[4]);
            long y3 = Long.parseLong(p[5]);

            if (containsOrigin(x1,y1,x2,y2,x3,y3)) count++;
        }
        br.close();

        System.out.println(count);
    }
}
