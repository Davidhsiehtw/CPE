// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int n;
	string s;
	map<string, int> mp;

	cin >> n;
	getline(cin, s); // clear '\n' 補充 2
	while (n--) {
		getline(cin, s);
		stringstream ss(s); // 補充
		ss >> s;
		mp[s]++;
	}
	map<string, int>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	map<string, int> mp;
	string s;
	int n;
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		stringstream ss(s);
		ss >> s;
		mp[s]++;
	}
	map<string, int>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}


/*
補充 2:
cin >> n; 這個 >> 只讀取數字 n，按下的 Enter 還會停留在輸入緩衝區
假設輸入：
3
Spain Donna Elvira
England Jane Doe
Spain Donna Anna

實際 buffer 會是：
3\nSpain Donna Elvira\England Jane Doe\nSpain Donna Anna\n

執行 cin >> n; 只讀取到 3
buffer 還剩下 \nSpain Donna Elvira\England Jane Doe\nSpain Donna Anna\n

若直接 getline(cin, s); 會讀取到 \n，s 會是空字串
所以要先執行 getline(cin, s); 來清掉這個 \n
*/

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
