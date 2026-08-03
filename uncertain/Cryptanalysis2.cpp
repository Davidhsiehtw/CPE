/*已 walkthrough 題目與解答*/
// 自己寫失敗 x1
// 這題必須熟悉C++的STL才較容易解題
// 第二次成功。
// 已自己寫過+檢討

// 寫法 1 這是正確的
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

int main(int argc, char *argv[]) {
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
	for (auto s : p) {
		if (s.second != 0)
			cout << s.first << " " << s.second << endl;
	}
	return 0;
}


// 寫法 2 有問題
/*
1. std::map 本身是有序的（按 key 排序）
	map 預設會按照 key（字母）遞增排序，而你要的是按照 value（頻率）降序排序，這
	與 map 的內部排序規則衝突。

2. std::map 不支援 sort()
	std::sort() 只能用在 隨機存取容器（如 vector、array），但 map 是 關聯容器，
	它的迭代器是 雙向迭代器，不符合 sort() 所需的 隨機存取 性質

為什麼 vector<pair<char, int>> 可以用 sort()？
    - vector 是 線性結構，可以隨意更改元素的位置，sort() 會重新排列 vector 裡的元
	素，完全符合你的需求。
	- map 的 key 是固定排序的，即使 value 改變，它的順序也不會變，所以無法用 sort()
	來改變 map 的順序。
如果一定要用 map，有解法嗎？
有，但你無法直接改變 map 的排序方式，而是可以：

1. 使用 multimap<int, char> 來手動改變排序方式
    先把 map<char, int> 轉存到 multimap<int, char, greater<int>>，讓它按照 value
	（頻率）降序排序。
2. 使用 vector<pair<char, int>> 來存取 map 並排序（這是你目前的方法）
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b) {
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

int main(int argc, char *argv[]) {
	map<char, int> p;
	for (int i = 0; i < 26; i++) {
		p['A' + i] = 0;
	}

	string s;
	int n;
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if ('a' <= s[i] && s[i] <= 'z') {
				p['A' + s[i] - 'a']++;
			}
			if ('A' <= s[i] && s[i] <= 'Z') {
				p['A' + s[i] - 'A']++;
			}
		}
	}

	sort(p.begin(), p.end(), cmp);

	map<char, int>::iterator i;
	for (i = p.begin(); i != p.end(); i++) {
		if (i->second != 0) cout << i->first << " " << i->second << endl;
	}
}
