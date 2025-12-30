/*已 walkthrough 題目與解答*/
// 以自己寫過+檢討

#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
	int n;
	string s;
	map<string, int> mp;

	cin >> n;
	getline(cin, s); // clear '\n'
	while (n--) {
		getline(cin, s);
		stringstream ss(s); // 補充
		ss >> s;
		mp[s]++;
	}

	for (const auto &m : mp) {
		cout << m.first << " " << m.second << endl;
	}

	return 0;
}

/*
補充:

string s = "Spain Donna Elvira";
stringstream ss(s);

這時候，ss 內部的緩衝區 就像這樣：

Spain Donna Elvira
↑
指標從開頭開始

當你執行：
ss >> s;

Spain Donna Elvira
	  ↑
	  指標現在指向這
*/
