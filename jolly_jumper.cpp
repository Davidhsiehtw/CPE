#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int n;
	while (cin >> n) {
		int d[n];
		for (int i = 0; i < n; i++)
			d[i] = 0;
		int pre, now;
		cin >> pre;
		for (int i = 1; i < n; i++) {
			cin >> now;
			d[abs(pre - now)]++;
			pre = now;
		}
		bool flag = true;
		for (int i = 1; i < n; i++) {
			if (d[i] != 1) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
}
