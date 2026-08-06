// g++4.6.3 AC
// d255: 11417 – GCD
// 教學: https://www.youtube.com/watch?v=fGesPF3QA1U&t=20s
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 輾轉相除法 求最大公因數
// 以較大的數除以較小的數，得到餘數後，再以較小的數除以餘數，如此反覆，直到餘數為0，最後一次的除數就是最大公因數。
// 例如：求48和18的最大公因數
// 48 ÷ 18 = 2...12
// 18 ÷ 12 = 1...6
// 12 ÷ 6 = 2...0
int GCD(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y; // x 更新成較小的數 y
        y = r; // y 更新成餘數 r
    }
    return x;
}

int main() {
	ios::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		if (N == 0) break;
		int G = 0;
		for (int i=1; i < N; i++)
			for (int j = i+1; j <= N; j++)
				G += GCD(i, j);
		cout << G << endl;
	}
}
