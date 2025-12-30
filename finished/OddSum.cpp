
#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	int a, b;
	for (int Case = 1; Case <= T; Case++) {
		int sum = 0;
		cin >> a >> b;
		if (a % 2) {
			for (;a <= b; a += 2)
				sum += a;
		}
		else if (a % 2 == 0) {
			a += 1;
			for (;a <= b; a += 2)
				sum += a;
		}
		cout << "Case " << Case << ": " << sum << endl;
	}
}


// 解答：
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	int T;
// 	cin >> T;
// 	int a, b;
// 	for (int Case = 1; Case <= T; Case++) {
// 		int sum = 0;
// 		cin >> a >> b;
// 		if (a % 2 == 0)
// 			a += 1;
// 		for (;a <= b; a += 2)
// 			sum += a;
// 		cout << "Case " << Case << ": " << sum << endl;
// 	}
// }
