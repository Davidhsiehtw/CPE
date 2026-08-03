// g++4.6.3 AC
// code: https://ithelp.ithome.com.tw/articles/10260696
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
	string s;
	bool flag = false;
	while (getline(cin, s)) {
		if (flag)
			cout << "\n";
		
		flag = true;
	
		int cnt[128] = {0};
		for (int i = 0; i < s.size(); i++) {
			cnt[int(s[i])]++;
		}
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 127; j >= 32; j--) {
				if (cnt[j] == i)
					cout << j << " " << i << "\n";
			}
		}
	}
}