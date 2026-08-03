// g++4.6.3 AC
//  寫法2 AC (非遞迴)
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n;
	while (cin >> n) {
		if (n == 0) return 0;
		int sum = 0;
		while (n > 0) {
			sum += n % 10; // 47
			n /= 10;

			if (n == 0 && sum >= 10) {
				n = sum;
				sum = 0;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

//  寫法1 AC (遞迴寫法)
/*#include <iostream>*/
/*using namespace std;*/
/**/
/*int f(int n) {*/
/*	int sum = 0;*/
/*	while (n > 0) {*/
/*		sum += n % 10;*/
/*		n /= 10;*/
/*	}*/
/*	if (sum < 10) return sum;*/
/*	else return f(sum);*/
/*}*/
/**/
/*int main() {*/
/*	int n;*/
/*	while (cin >> n) {*/
/*		if (n == 0) return 0;*/
/*		cout << f(n) << endl;*/
/*	}*/
/*	return 0;*/
/*}*/


