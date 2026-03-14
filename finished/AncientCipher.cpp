// 題目: https://cpe.mcu.edu.tw/cpe/problemPdf/1339.pdf
// 解題思路: https://zerojudge.tw/ShowThread?postid=32707&reply=0
// 心得，這題題目較長，比較難想到這樣的解法
// 看中文題目 + 提示花了 55 分鐘
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, s2;
    while (cin >> s >> s2) {
        int cnt[26] = {0};
        int cnt2[26] = {0};

        for (int i = 0; i < s.size(); i++)
            cnt[s[i] - 'A']++;
        for (int i = 0; i < s2.size(); i++)
            cnt2[s2[i] - 'A']++;

        sort(cnt, cnt+26);
        sort(cnt2, cnt2+26);

        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != cnt2[i]) {
                flag = false;
                break;
            }
        }
        if (!flag) cout << "NO\n";
        else cout << "YES\n";
    }
}

        // 查看排序後的陣列
        /*for (int i = 0; i < 26; i++) cout << cnt[i] << " ";*/
        /*cout << "\n";*/
        /*for (int i = 0; i < 26; i++) cout << cnt2[i] << " ";*/

/*
 *
發現兩個字串每個"字母"出現的次數是一樣的話就是Yes
JJ
PP
UWDSTV
-> 2 + 2 + 7

II
OO
USVCTR

jwpudjstvp
victorious
mama
rome
haha
hehe
aaa
aaa
neercisthebest
secretmessages

*/



