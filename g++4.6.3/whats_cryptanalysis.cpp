// 這題必須熟悉C++的STL才較容易解題
// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b) {
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(0);
	vector<pair<char, int>> p(26);
	for (int i = 0; i < 26; i++) {
		p[i].first = 'A' + i;
	}
	string s;
	int n;
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if ('a' <= s[i] && s[i] <= 'z') {
				p[s[i] - 'a'].second++;
			}
			if ('A' <= s[i] && s[i] <= 'Z') {
				p[s[i] - 'A'].second++;
			}
		}
	}
	sort(p.begin(), p.end(), cmp);
	vector<pair<char,int> >::iterator it;
	for (it = p.begin(); it != p.end(); ++it) {
		if (it->second != 0)
			cout << it->first << " " << it->second << endl;
	}	
	return 0;
}

