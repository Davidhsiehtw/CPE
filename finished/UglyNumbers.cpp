#include <bits/stdc++.h>
using namespace std;
int a[1505];
int main() {
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    a[5] = 5;
    for (int i = 6; i <= 1500; i++) {
        int i2 = 1, i3 = 1, i5 = 1;
        while (2 * a[i2] <= a[i-1]) i2++;
        while (3 * a[i3] <= a[i-1]) i3++;
        while (5 * a[i5] <= a[i-1]) i5++;
        a[i] = min({2 * a[i2], 3 * a[i3], 5 * a[i5]});
    }
    cout << "The 1500'th ugly number is " << a[1500] << ".\n";
}




/*
 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15
 1 = 5^0 x 3^0 x 2^0
 2 = 5^0 x 3^0 x 2^1
 3 = 5^0 x 3^1 x 2^0
 4 = 5^0 x 3^0 x 2^2
 5 = 5^1 x 3^0 x 2^0
 6 = 5^0 x 3^1 x 2^1
*/







/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int ugly[1505];*/
/*int main() {*/
/*    // 假設 0-based 陣列 ugly[0] = 1; int i=1; // 從第2個開始生成*/
/*    int i2=1, i3=1, i5=1;  // 指標從0開始（指向 ugly[0]=1）*/
/*    for(int idx=1; idx<=1500; idx++) {  // 生成到第n個*/
/*        int next2 = ugly[i2] * 2;*/
/*        int next3 = ugly[i3] * 3;*/
/*        int next5 = ugly[i5] * 5;*/
/**/
/*        int next_ugly = min({next2, next3, next5});  // 取最小*/
/*        ugly[idx] = next_ugly;*/
/**/
/*        // 推進：誰的候選被選中，就++（允許多個）*/
/*        if(next_ugly == next2) i2++;*/
/*        if(next_ugly == next3) i3++;*/
/*        if(next_ugly == next5) i5++;*/
/*    }*/
/*    cout << "The 0'th ugly number is " << ugly[0] << ".\n";*/
/*    cout << "The 1'th ugly number is " << ugly[1] << ".\n";*/
/*    cout << "The 2'th ugly number is " << ugly[2] << ".\n";*/
/*    cout << "The 3'th ugly number is " << ugly[3] << ".\n";*/
/*}*/
