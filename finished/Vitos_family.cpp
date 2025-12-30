/*中位數解法 and 三分搜尋法：https://hackmd.io/@ShanC/ternary-search#*/

/*已 walkthrough 題目與解答*/
/*已自己寫過+檢討*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, r, a[30000];	
	int mid, dis;

	cin >> t;
	while (t--) {
		cin >> r;
		for (int i = 0; i < r; i++) {
			cin >> a[i];
		}
		sort(a, a+r);

		dis = 0;
		mid = a[r / 2];
		for (int i = 0; i < r; i++) {
			dis += abs(a[i] - mid);
		}
		cout << dis << "\n";
	}
	return 0;
}