#include <bits/stdc++.h>
using namespace std;
int main() {
	map<char, vector<int>> mp;
	//         0  1  2  3  4  5  6  7  8  9  10
	mp['c'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
	mp['d'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	mp['e'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	mp['f'] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	mp['g'] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	mp['a'] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['b'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	mp['C'] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['D'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	mp['E'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	mp['F'] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	mp['G'] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	mp['A'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['B'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	
	string s;
	int t;
	cin >> t;
	getline(cin, s); //clear buffer
	while (t--) {
		getline(cin, s);
		int cnt[11] = {0};
		int a[11] = {0}; // status
		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; j <= 10; j++) {
				if (mp[s[i]][j]) { // 查詢該音調的表
					if (a[j]) { // 若按住
						continue;
					} else {
						a[j] = 1; // 標記按住的狀態
						cnt[j]++; 
					}
				} else {
					a[j] = 0; // 切換為沒按住
				}
				
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (i < 10) cout << cnt[i] << " ";
			else cout << cnt[i];
		}
		cout << "\n";
	}
}



// Mar 13 嘗試寫第二次
// 留意 if (a[j] == 1) continue; 邏輯需包在 if (mp[s[i]][j]) 裡面
#include <bits/stdc++.h>
using namespace std;
int main() {
	map<char, vector<int>> mp;
	//         0  1  2  3  4  5  6  7  8  9  10
	mp['c'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
	mp['d'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	mp['e'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	mp['f'] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	mp['g'] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	mp['a'] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['b'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	mp['C'] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['D'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	mp['E'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	mp['F'] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	mp['G'] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	mp['A'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['B'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};	
	
	int t;
	string s;
	cin >> t;
	getline(cin, s); // clear buffer
	while (t--) {
		getline(cin, s);
		int cnt[11] = {0};
		int a[11] = {0};
		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; j <= 10; j++) {
				if (mp[s[i]][j]) {
					if (a[j] == 1)
						continue;
					
					cnt[j]++; // 沒被標記才累計
					a[j] = 1; // 標記為按住
				} else {
					a[j] = 0; // 放掉
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (i < 10) cout << cnt[i] << " ";
			else cout << cnt[i];
		}
		cout << "\n";
	}
}
