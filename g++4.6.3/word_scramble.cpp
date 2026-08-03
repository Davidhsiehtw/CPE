// g++4.6.3 AC
// 2025-09-30 考題
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	string s;
	while (getline(cin, s)) {
		istringstream ss(s); // 卡在 ss >> s，以及宣告
		bool first = true;
		while (ss >> s) {
			if (!first) cout << " ";
				first = false;
            reverse(s.begin(), s.end());
            cout << s;
		}
		cout << "\n"; 
	}
}