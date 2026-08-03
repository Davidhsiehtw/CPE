/*中位數解法 and 三分搜尋法：https://hackmd.io/@ShanC/ternary-search#*/
// g++4.6.3 AC
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
		cout << dis << "\n";
	}
	return 0;
}