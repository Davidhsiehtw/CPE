// code: https://github.com/Omar-Rehan/Competitive-Programming-Solutions/blob/master/UVA%20%2310257%20Dick%20and%20Jane.cpp
// 題目: https://onlinejudge.org/external/102/10257.pdf
#include<bits/stdc++.h>
using namespace std;

int main() {
    int s, p, y, j;
    while (scanf("%d %d %d %d", &s, &p, &y, &j) != EOF) {
        int turtle = (j + 12 - y - p) / 3;
        int cat = (j + 12 - s - turtle) / 2;
        int dog = (j + 12 - cat - turtle);
        cout << dog << " " << cat << " " << turtle << "\n";
    }
}

// D, C, T: 分別實際年齡 (小寫表示年齡差)
// Spot s 歲 當 Puff 出生     
// Puff p 歲 當 Yertle 出生   
// Spot y 歲 當 Yertle 出生   

/*
    D + C + T = 12 + j
    D - C = s
    C - T = p
    D - T = y

    (T + y) + (T + p) + T = 12 + j
->  3T + y + p = 12 + j
->  T = (12 + j - y - p) / 3 ---- (1)

    (C + s) + C + T = 12 + j
->  2C + s + T = 12 + j
->  C = (12 + j - s - T) / 2 ---- (2)

    D = 12 + j - C - T       ---- (3)
*/
