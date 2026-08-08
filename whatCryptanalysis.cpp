// Zero Judge AC
// TODO: 瘋狂程設要測
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n, max_cnt = 0;
    int code[26] = {0};
    string s;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++) {
            char c = tolower(s[j]);
            if ('a' <= c && c <= 'z') {
                code[c - 'a']++;
                max_cnt = max(max_cnt, code[c - 'a']); // cnt從39->7 (預設測資)
            }
        }
    }
    /*cout << "max_cnt: " << max_cnt << endl;*/
    for (int j = max_cnt; j >= 1; j--)
        for (int i = 0; i < 26; i++)
            if (code[i] == j)
                cout << (char)(i + 'A') << " " << code[i] << endl;
}

