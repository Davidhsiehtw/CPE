// g++4.6.3 AC @ May 30 16:44
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int x, y;

	while (cin >> x >> y) {
		int carry  = 0;
		int cnt = 0;
		if (x == 0 && y == 0) break;
		
		while (x > 0 || y > 0) {
			int t = x % 10 + y % 10 + carry;
			if (t >= 10) {
				cnt++;
				carry = 1; // 這禮遇第一次寫不一樣
			} else {
				carry = 0;
			}
			
			x /= 10;
			y /= 10;
		}
		if (cnt == 0) {
			cout << "No carry operation." << endl;
		} else if (cnt == 1) {
			cout << cnt << " carry operation." << endl;	
		} else {
			cout << cnt << " carry operations." << endl;
		}
	}
}
