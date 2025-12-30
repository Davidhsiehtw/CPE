    /*已 walkthrough 題目與解答*/
// 以自己寫過+檢討

// 寫法 1
// 已自己寫過，但需注意string s[] 長度要 > 100 否則編譯器不給對，
// 更有彈性的寫法由 Gork 3 編寫如下方
#include <iostream>
#include <algorithm>
using namespace std;

string s[100];

int main() {
	// row = max(輸入的 col)
	int row = 0, col = 0;
	while (getline(cin, s[col])) {
		row = max(row, (int) s[col].size());
		col++;
	}
	for (int i = 0; i < row; i++) {
		for (int j = col - 1; j >= 0 ; j--) {
			if (i >= s[j].size()) cout << " ";
			else cout << s[j][i];
		}
		cout << endl;
	}
	return 0;
}

// 寫法 2: vector<string> 動態儲存輸入，無需擔心固定大小。
/*#include <iostream>*/
/*#include <vector>*/
/*#include <algorithm>*/
/*using namespace std;*/
/**/
/*int main() {*/
/*    vector<string> s;  // 使用 vector 代替固定陣列*/
/*    string line;*/
/*    int row = 0;*/
/**/
/*    // 讀取輸入*/
/*    while (getline(cin, line)) {*/
/*        s.push_back(line);*/
/*        row = max(row, (int)line.size());*/
/*    }*/
/**/
/*    int col = s.size();  // 總行數*/
/*    // 輸出旋轉結果*/
/*    for (int i = 0; i < row; i++) {*/
/*        for (int j = col - 1; j >= 0; j--) {*/
/*            if (i >= s[j].size()) cout << " ";*/
/*            else cout << s[j][i];*/
/*        }*/
/*        cout << endl;*/
/*    }*/
/*    return 0;*/
/*}*/

// 寫法一推導：
// 以順時針旋轉90度後來看，row 與 col
// (0, 0) (0, 1) (0, 2)
// (1, 0) (1, 1) (1, 2)
string ss[] = {
	"Rene Decartes once said,",
	"I think, therevpvpddfore I am."
};
