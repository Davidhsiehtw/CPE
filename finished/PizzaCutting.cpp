/**
範例輸入
5
10
-100
範例輸出
16
56
*/


#include <iostream>
using namespace std;
int main() {
    long long n;
    while (cin >> n){
        if (n < 0) break;
        cout << n * (n+1) / 2 + 1 << endl;
    }
    return 0;
}

// BAD :( cause TLE
// #include <iostream>
// #include <map>
// using namespace std;
// int main() {
//     long long n;
//     map<int, int> mp;
//     mp[0] = 1;
//     mp[1] = 2;
//     for (int i = 2; i <= 210000000; i++) {
//         mp[i] = mp[i-1] + i;
//     }
//     while (cin >> n) {
//         if (n < 0) break;
//         cout << mp[n] << endl;
//     }
// }

/**

- 其中，N是指輸入，P是指 pieces。我之後看人家推導，然後自己在紙上推推看得到：
    N P
    0 1 -> 1
    1 2 -> 1+1
    2 4 -> 2+2 -> 1+1+2
    3 7 -> 4+3 -> 2+2+3 -> 1+1+2+3
    4 11-> 7+4 -> 4+3+4 -> 2+2+3+4 -> 1+1+2+3+4
    最後觀察到，1+(1+2+...+N) 可以寫成公式 1+N*(N+1)/2
但是，當下我只有思考到
   0 1 -> 1
   1 2 -> 1+1
   2 4 -> 2+2
   3 7 -> 4+3
   4 11 -> 7+4
我其實有想到，7可以拆分成4+3，但必須先算完N=4的值，4可以拆成2+2，但必須先算完N=2的值，以此類推。
我是用這樣的思維在解題。當下有隱約猜到或許可簡化成某公式，但我就沒有像上述那樣操作。我到底缺乏什麼，每一次都這樣。

- 我的思維是否 overfitting?
 */
