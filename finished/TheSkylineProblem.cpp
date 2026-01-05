// 小心多印空格，會導致 UVa 的 Presentation error
// 

#include <bits/stdc++.h>
using namespace std;
int high[10000];
int main() {
    int Li, Hi, Ri;
    int mx = 0;
    int mn = 10000;
    // 一頓輸入
    while (cin >> Li >> Hi >> Ri) {
        mn = min(Li, mn);
        mx = max(Ri, mx);
        // high[1..5] 是 11
        // high[2..5] 是 11
        // high[6..7] 是 6
        // high[3..9] 是 13
        // 所以目前：high[1]~high[2] 是 11；high[3]~hgih[9] 是 13
        for (int i = Li; i < Ri; i++) { // 注意不是 i<=Ri，因為那個位置是垂直線
            high[i] = max(high[i], Hi);
        }
    }
    // 一頓輸出
    // high[i] = v 如下
    // i: 0  1  2  3  4  5    
    // v: 0 11 11 13 13 13 ...
    Hi = -1;
    for (int i = mn; i <= mx; i++) {
        if (high[i] != Hi) {
            if (i == mx) cout << i << " " << high[i];
            else cout << i << " " << high[i] << " ";
            Hi = high[i];
        }
    }
    cout << "\n";
    return 0;
}

/**

1 11 5
2 6 7
3 13 9
12 7 16
14 3 25
19 18 22
23 13 29
24 4 28


 */




/*#include <iostream>*/
/*using namespace std;*/
/*int high[10005];*/
/*int main() {*/
/*    int L, H, R;*/
/*    int mn = 10000, mx = 0;*/
/*    while (cin >> L >> H >> R){*/
/*        mn = min(mn, L);*/
/*        mx = max(mx, R);*/
/*        for (int i = L; i < R; i++){*/
/*            high[i] = max(high[i], H);*/
/*        }*/
/*    }*/
/*    H = -1;*/
/*    for (int i = mn; i <=mx; i++){*/
/*        if (high[i] != H) {*/
/*            cout << i << " " << high[i] << " ";*/
/*            H = high[i];*/
/*        }*/
/*    }*/
/*    cout << "\n";*/
/*}*/
