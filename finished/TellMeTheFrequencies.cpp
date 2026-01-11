// 第一遍練這題，放棄直接看解答。不熟 pair 與 sort() 當中的 cmp 觀念。
// 花了3h37m :)

/**
 - sort(v, v+256, cmp); sort 會在內部自動挑出兩個元素 a、b，並呼叫 cmp(a, b)
 - cmp(a, b) 被怎麼用？ sort 內部會不停做這種判斷：
    if (cmp(x, y)) { // x 放在 y 前面 } 
    else { // x 不放在 y 前 }
    
    cmp(a, b) 的本質就是回答這個問題：「這兩個元素 a, b，哪個應該排在前面？」
    - 回傳 true → a 放前
    - 回傳 false → b 放前
    - 理論上 index a 會比 index b 小
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    // 根據出現的次數由小到大輸出 (須考慮是否相等，若相等，則考慮ASCII 較大的先輸出)
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first > b.first;
    // 如果有2個以上的字元有相同的次數，則ASCII值較大的先輸出
}

int main() {
    string str;
    bool first = true;
    while (getline(cin, str)) {
        // 在輸出前 (非第一筆時) 印換行
        if (!first)
            cout << "\n";
        first = false;

        // init
        pair<int, int> v[256]; // why 256?
        for (int i = 0; i < 256; i++) {
            v[i] = {i, 0};
        }
        // 紀錄
        for (int i = 0; i < str.size(); i++) {
            v[(int)str[i]].second++;
        }

        sort(v, v + 256, cmp);

        for (auto i : v) {
            if (i.second > 0)
                cout << i.first << " " << i.second << "\n";
        }
        /*cout << "\n"; // 怎麼改成，當最後一筆測資時，不要 cout << "\n";*/
    }
}
