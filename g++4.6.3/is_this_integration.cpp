// code: Gemni
// chat session: https://gemini.google.com/app/a43c86f02779e8df
// ZeroJudge題目：https://zerojudge.tw/ShowProblem?problemid=n761

// g++ 4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    double a;
    while (cin >> a) {
        // 套用推導出的係數
        double x = a * a * (1.0 - sqrt(3.0) + M_PI / 3.0);
        double y = a * a * (2.0 * sqrt(3.0) + M_PI / 3.0 - 4.0);
        double z = a * a - x - y; // gpt 改過，已 AC
        cout << fixed << setprecision(3);
        cout << x << " " << y << " " << z << "\n";
    }
    return 0;
}
