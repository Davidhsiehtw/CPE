/*中位數解法 and 三分搜尋法：https://hackmd.io/@ShanC/ternary-search#*/
// 批改交卷：不通過，但卻顯示 SAME
// 十組隨機測資 SAME
// 預設測資 SAME
// 不寫 ios::sync_with_stdio(0); 會 NO-OUTPUT
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
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
		cout << dis << endl;
	}
	return 0;
}
