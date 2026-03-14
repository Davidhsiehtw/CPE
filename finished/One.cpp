#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int cnt = 1;
		int c = 1;
		while (c % n) {
            // 新餘數 = (舊餘數 * 10 + 1) mod n
            c = (c * 10 + 1) % n;
			cnt++;
		}
		cout << cnt << "\n";
	}
}
