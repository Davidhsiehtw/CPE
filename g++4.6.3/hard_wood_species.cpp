// g++ 4.6.3 AC
// 不能使用 printf() 只能用 cout
// 必須加這行 ios::sync_with_stdio(0); 

/*
GPT 表示：
問題 1：程式其實會「卡在輸入」
    `while (getline(cin, s) && s != "")` 讀到空行 "" 或是 EOF，
    但實際輸入可能沒有空行，如下：
    ```
    1
    abc
    def
    ```
    此時執行狀態：
    getline → "abc"
    getline → "def"
    getline → 等下一行（卡住）所以根本還沒走到輸出

問題 2：buffer 沒 flush → 看起來像 NO OUTPUT
    預設是 `ios::sync_with_stdio(true);`

結論就是一定要加  ios::sync_with_stdio(false); 就不會有事
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);  // 必須加這行，
    string s;
    int n;
    cin >> n;
    int c = n; // 紀錄幾筆測資，之後要為了避免 Presentation Error (PE)*/
    getline(cin, s); // clear buffer
    getline(cin, s); // blank space
    while (n--) {
        int sum = 0;
        map<string, int> mp;

        while (getline(cin, s) && s != "") {
            mp[s]++;
            sum++;
        }

		cout << fixed << setprecision(4);// 移到 loop 外比較乾淨
        for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << " " << (double)it->second / sum * 100 << "\n";
        }

        if (c != 1 && n != 0)
            cout << "\n";
    }
}