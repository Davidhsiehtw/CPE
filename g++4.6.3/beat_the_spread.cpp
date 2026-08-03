// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int n, s, d, a, b;
	cin >> n;
	while (n--) {
		cin >> s >> d;
		if (s < d || (s+d) % 2)
			cout << "impossible\n";
		else {
			a = 0.5 * (s + d);
			b = 0.5 * (s - d);
			cout << a << " " << b << "\n";
		}
	}
}