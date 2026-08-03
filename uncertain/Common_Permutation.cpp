/*已 walkthrough 題目與解答*/
/*已自己寫過+檢討*/
// 更好的解法： https://hackmd.io/@LukeTseng/rkuh9L9Hge#11-Common-Permutation
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	string a, b;

	// 雖然 Zero Judge 給我，但 OnlineJudge 會 WA
	/*while (cin >> a >> b) {*/ // 會忽略前導空白與換行
	// 在範例輸入給的測資讀取上沒問題，但是輸入變成：
	// hello world
    // programming is fun
	// a = hello
	// b = world
	// 這會是一個 edge case。
	// 「競程、系統設計的常識」： 輸入格式可能是陷阱，永遠要假設測資不友善

	while (getline(cin, a) && getline(cin, b)) {
		int cnta[26] = {0}, cntb[26] = {0};

		for (int i = 0; i < a.size(); i++) {
			cnta[a[i] - 'a']++;
		}
		for (int i = 0; i < b.size(); i++) {
			cntb[b[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < min(cnta[i], cntb[i]); j++) {
				cout << (char) ('a' + i);
			}
		}
		cout << endl;
	}
	return 0;
}
