// g++4.6.3 AC
// 耗時 30m30s @ May 15 16:07
// 小卡在邊緣案例 m=1 的情況。

#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	vector<int> a;
	int n, m;
	while (cin >> n >> m) {
		bool boring = false;
		a.clear();
		if (m == 1)
			boring = true;
		else
			a.push_back(n);
			
		while (n != 1 && m != 1) {
			if (n % m != 0) {
				boring = true;
				break;
			} else {
				n = n / m;
				a.push_back(n);
			}
		}
		
		if (!boring) {
			for (int i = 0; i < a.size(); i++) {
				if (i == a.size()-1)
					cout << a[i];
				else
					cout << a[i] << ' ';
			}
			cout << "\n";
		} else {
			cout << "Boring!" << "\n";
		}
	}
}
