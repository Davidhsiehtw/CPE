// 我習慣的寫法
#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	int N;
	int Case = 1;
	string S1, S2;
	cin >> N;
	while (N--) {
		cin >> S1 >> S2;
		int n1=0, n2=0;
		for (int i = 0; i < S1.size(); i++) {
			n1 *= 2;
			n1 += S1[i] - '0';
		}
		for (int i = 0; i < S2.size(); i++) {
			n2 *= 2;
			n2 += S2[i] - '0';
		}
		if (gcd(n1, n2) > 1)
			cout << "Pair #" << Case++ << ": All you need is love!\n";
		else
			cout << "Pair #" << Case++ << ": Love is not all you need!\n";
	}
}



// chatGPT 討論: https://chatgpt.com/c/69368fd2-20a4-8320-bf2d-ed302eb494d1
#include <iostream>
using namespace std;

// 我認為比較好讀的實作
int mygcd(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y; // x 更新成較小的數 y
        y = r; // y 更新成餘數 r
    }
    return x;
}

/*int mygcd(int x, int y){*/
/*    while (x != 0 && y != 0) {*/
/*        // 永遠讓比較大的那個數去除比較小的那個數。*/
/*        if (x >= y)*/
/*            x = x % y;*/
/*        else*/
/*            y = y % x;*/
/*    }*/
/*    return x + y;*/
/*}*/

int main() {
    ios::sync_with_stdio(0); // 必要
    int N;
    string S1, S2;
    cin >> N;
    for (int Case = 1; Case <= N; Case++){
        cin >> S1 >> S2;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < S1.size(); i++){ // NOTE
            n1 *= 2;
            n1 += S1[i] - '0';
        }
        for (int i = 0; i < S2.size(); i++){
            n2 *= 2;
            n2 += S2[i] - '0';
        }
        cout << "Pair #" << Case;
        if (mygcd(n1, n2) > 1) cout << ": All you need is love!\n";
        else cout << ": Love is not all you need!\n";
    }
    return 0;
}

/*
NOTE:
    10 / 2 = 5 ... 0
    5 / 2 = 2 ... 1
    2 / 2 = 1 ... 0
    1 / 2 = 0 ... 1

    反過來，由下往上返回

    0*2 + 1 = 1
    1*2 + 0 = 2
    2*2 + 1 = 5
    5*2 + 0 = 10

    -> value = value * base + digit; 
 * */
