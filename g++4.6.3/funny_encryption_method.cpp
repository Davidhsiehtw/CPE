// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		int X1 = n;
		int b1=0; // CAVEAT: 要初始化
		while (X1 > 0) {
			b1 += (X1 % 2);
			X1 /= 2;
		}

		int x, b2=0;
		X1 = n;
		while (X1) {
			x = X1 % 10;
			while (x) {
				b2 += x % 2;
				x /= 2;
			}
			X1 /= 10;
		}

		cout << b1 << " " << b2 << endl;
	}
	return 0;
}
/*
3
265
111
1234

// X1 = 265 -> b2 = 10 0110 0101(binary) 推導

// 265 % 10 = 5
// 26 % 10  = 6
// 2 % 10   = 2
// =>
// x = X1 % 10 start
// X1 / 10 end

// 5 % 2 = 1
// 5 /= 2 -> 2
// 2 % 2 = 0
// 2 /= 2 -> 1
// 1 % 2 = 1
// 1 /= 2 -> 0
// =>
// b2 += x % 2 middle
// x /= 2      middle


 */
