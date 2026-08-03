// g++4.6.3 AC
/*
必須知道：
- 題目關鍵句 "The given numbers can contain up to 1001 digits."
- 輸入數字可能達到 1000 位數，必須以字串形式讀入
- 如果一個數字是 11 的倍數，其「奇數位數的數字和」與「偶數位數的數字和」的差也是 11 的倍數。
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	string s;
	while (cin >> s) {
		if (s == "0") break;

		int odd = 0, even = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i % 2) {
				odd += s[i] - '0'; // 錯在 + [*註1]
			} else {
				even += s[i] - '0'; // 錯在 +
			}
		}

		if ((odd - even) % 11 == 0) {
			cout << s << " is a multiple of 11.\n";
		} else {
			cout << s << " is not a multiple of 11.\n";
		}
	}
	return 0;
}
