// 題目: https://cpe.mcu.edu.tw/cpe/problemPdf/1585.pdf
// 耗時 6:45，無任何輔助
// Online Judge: AC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    string s;
    int cnt = 0;
    int sum = 0;
    cin >> t;
    while (t--) {
        cin >> s;
        sum = 0;
        cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'O') {
                sum += ++cnt;
            } else {
                cnt = 0;
            }
        }
        cout << sum << "\n";
    }
}

