#include <bits/stdc++.h>
using namespace std;

// 假設 {66, 2} 與 {65, 3} 比較。
// 因 a.second > b.second，即 return false。那麼，sort 會將 v 兩個pair順序對調？
bool cmp(pair<int, int> a, pair<int, int> b) {
    // 假設reutrn fasle，則意味著 a 不應該排在 b 前。並不意味著立即 swap
    // 真正的排序是排序器內部根據整個比較網絡來安排元素順序。
    if (a.second != b.second)
        return a.second < b.second;
    else return a.first > b.first;
}

int main() {
    string s;
    bool first = true;
    pair<int, int> v[128];
    while (getline(cin, s)) {
        if (!first)
            cout << "\n";
        first = false;

        for (int i = 0; i < 128; i++) {
            v[i] = {i, 0};
        }

        for (int i = 0; i < s.size(); i++) {
            v[(int)s[i]].second++;
        }
        // cmp
        sort(v, v+128, cmp);

        for (auto i : v) {
            if (i.second > 0)
                cout << i.first << " " << i.second << "\n";
        }
    }
}
