#include <bits/stdc++.h>
using namespace std;
#define DEG2RAD(theta) ((theta) * M_PI / 180.0)
int main() {
    double s, a;
    string str;
    double chord, arc;
    const double r = 6440.0;
    while (cin >> s >> a >> str) {
        if (str == "min")
            a = a / 60;

        // UVa 加上這個判斷可過，但是瘋狂程設不行
        /*while (a > 360) a -= 360;*/

        if (a > 180) // edge case
            a = 360 - a;
        arc = (s + r) * 2 * M_PI * (a/360);
        chord = 2 * (r+s) * sin(DEG2RAD(a/2.0));
        printf("%.6f %.6f\n", arc, chord);
    }
}

