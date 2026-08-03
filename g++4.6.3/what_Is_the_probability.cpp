// g++4.6.3 AC 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int t;
	int N, i;
	double p;
	cin >> t;
	while (t--) {
		cin >> N >> p >> i;
		if (p == 0) { cout << "0.0000\n"; continue; } 
		// Sn =  a / 1 - r
		double a = pow(1.0 - p, i - 1) * p;
		double r = pow(1.0 - p, N);
		cout << fixed << setprecision(4);
		cout << a / (1 - r) << "\n";
	}
}


// Grok 解題思路: https://grok.com/share/bGVnYWN5_dbd33001-7107-4827-a9c4-7375d9d4728d
// 看完 Gork 解析公式，其實有懂，但我寫不出來還不一定
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	int t;
// 	double p;
// 	int N, i;
// 	cin >> t;
// 	while (t--) {
// 		cin >> N >> p >> i;
// 		if ( p == 0) {
// 			cout << "0.0000\n";
// 			continue;
// 		}
// 		// 等比級數: a / 1 - r;
// 		double a = pow(1.0 - p, i-1) * p;
// 		double r = pow(1.0 - p, N);
// 		printf("%.4f\n", a / (1.0 - r));
// 		// cout << a / (1.0 - r) << "\n";
// 	}
// }