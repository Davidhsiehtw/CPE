// 22m34s
// Mar 21 10:52
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, N;
    cin >> t;
    while (t--) {
        string s="";
        int cnt[10000] = {0};
        cin >> N; // 3
        for (int i = 1; i <= N; i++) {
            s += to_string(i);
        }

        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - '0']++;
        }
    
        for (int i = 0; i < 10; i++) {
            if (i < 9) cout << cnt[i] << " ";
            else cout << cnt[i];;
        }
        cout << "\n";
    }
}
/*
2
3
13

*/
