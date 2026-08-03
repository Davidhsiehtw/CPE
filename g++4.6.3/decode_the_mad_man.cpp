// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	string s[] = {
		"`1234567890-=",
		"~!@#$%^&*()_+",
		"qwertyuiop[]\\",
		"asdfghjkl;'",
		"zxcvbnm,./"
	};
	map<char, char> mp;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 2; j < s[i].size(); j++) {
			 mp[s[i][j]] = s[i][j-2];
		}
	}
	
	string n;
	getline(cin, n); // clear buffer
	while (getline(cin, n)) {
		for (int i = 0; i < n.size(); i++) {
			n[i] = tolower(n[i]); // NOTE: 測資會故意給大寫，所以要先轉小寫
			if (n[i] != ' ')
				cout << mp[n[i]];
			else
				cout << " ";
		}
		cout << "\n";
	}
}

// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	string s[] = {
		"`1234567890-=",
		"~!@#$%^&*()_+",
		"qwertyuiop[]\\",
		"asdfghjkl;'",
		"zxcvbnm,./"
	};
	map<char, char> mp;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 2; j < s[i].size(); j++) {
			 mp[s[i][j]] = s[i][j-2];
		}
	}
	
	int n;
	cin >> n;
	string x;
	getline(cin, x); // clear buffer
	while (n--) {
		getline(cin, x);
		for (int i = 0; i < x.size(); i++) {
			x[i] = tolower(x[i]);
			if (x[i] != ' ') cout << mp[x[i]];
			else cout << " ";
		}
		cout << endl;
	}
}
