// 所有 ugly 都是舊 ugly × {2,3,5} 組成
// a[i] = min(
//     比a[i-1]大的ugly, // 2的倍數
//     比a[i-1]大的ugly, // 3的倍數
//     比a[i-1]大的ugly) // 5的倍數 

#include <bits/stdc++.h>
using namespace std;
int a[1501];
int main() {
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    a[5] = 5;
    int i2 = 1, i3 = 1, i5 = 1;
    for (int i = 6; i < 1501; i++) {
        while (a[i2] * 2 <= a[i-1]) i2++;
        while (a[i3] * 3 <= a[i-1]) i3++;
        while (a[i5] * 5 <= a[i-1]) i5++;
        a[i] = min({a[i2] * 2, a[i3] * 3, a[i5] * 5});
    }
    cout << "The 1500'th ugly number is " << a[1500] << ".\n";
}
