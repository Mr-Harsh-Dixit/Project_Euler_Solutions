#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

static long long cross(long long ax, long long ay, long long bx, long long by) {
    return ax * by - ay * bx;
}

static bool containsOrigin(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3) {
    long long s1 = cross(x2 - x1, y2 - y1, -x1, -y1);
    long long s2 = cross(x3 - x2, y3 - y2, -x2, -y2);
    long long s3 = cross(x1 - x3, y1 - y3, -x3, -y3);

    if (s1 == 0 || s2 == 0 || s3 == 0) return false; // strict interior

    bool hasPos = (s1 > 0) || (s2 > 0) || (s3 > 0);
    bool hasNeg = (s1 < 0) || (s2 < 0) || (s3 < 0);
    return !(hasPos && hasNeg);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream in("triangles.txt");
    string line;
    long long cnt = 0;

    while (getline(in, line)) {
        // Replace commas with spaces, then read ints
        for (char &c : line) if (c == ',') c = ' ';
        stringstream ss(line);
        long long x1,y1,x2,y2,x3,y3;
        if (!(ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) continue;

        if (containsOrigin(x1,y1,x2,y2,x3,y3)) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
