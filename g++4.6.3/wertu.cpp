// g++4.6.3 AC
// 不能使用 printf() 只能用 cout
// 必須加這行 ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	string s = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	string line;
	while (getline(cin, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ' ') {
				cout << " ";
				continue;
			}
			for (int j = 0; j < s.size(); j++) {
				if (line[i] == s[j])
					cout << s[j-1];
			}
		}
		cout << "\n";
	}
}