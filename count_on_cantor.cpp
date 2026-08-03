// 參考解答:https://czone6.notion.site/00264-Count-on-Cantor-60f1a9e2648e44cd83bd743033ebf233
// g++4.6.3 AC 耗時約 1h，@ May 12 11:21
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int n;
	int x, y;
	while (cin >> n) {
		int level = 1;
		int TERM = n;
		
		while (n > level) { // 14 > 1
			n -= level; // 14-=1, 13-=2, 11-=3, 8-=4, 4-=5
			level++; // 2
		}
		
		// even 由右往左
		if (level % 2 == 0) {
			x = 1, y = level; // 1 2
			for (int i = 0; i < n-1; i++) {
				x++;
				y--;
			}
		} else {
			x = level, y = 1;
			for (int i = 0; i < n - 1; i++) {
				x--;
				y++;
			}
		}
		cout << "TERM " << TERM << " IS " << x << "/" << y << "\n";
	}
}
