// g++4.6.3 AC
// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int I;
	// NOTE:
	// '0' + (I % 2)，其中，'0'是 char，但在運算時會發生 char -> int
	// '0' == 48，是 ASCII。
	// 則算式變成 48 + 0 = 48 或是 48 + 1 = 49
	// 再轉回 char (因為 strnig += 可以吃 char)
	// 48 → '0'
    // 49 → '1'
	// cout << '0' + 1 << "\n";       // 49 範例 code
	// cout << char('0' + 1) << "\n"; // 1  範例 code
	while (cin >> I) {
		if (I == 0) break;
		int P = 0;
		string B = "";
		
		while (I > 0) {
			B += '0' + (I % 2); // NOTE
			if (I % 2 == 1) P++;
			I >>=1; // I = I >> 1; 右移一位，相當於 I 除以 2 的整數除法 // 10 -> 5 -> 2 -> 1
		}
		reverse(B.begin(), B.end());
		cout << "The parity of " << B << " is " << P << " (mod 2)." << "\n";
	}
}
