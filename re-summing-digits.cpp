#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	
	while (cin >> n) {
		if (n == 0) break;
		int sum = 0;

		while (n > 0) { // remains 47
			sum += n % 10;
			n /= 10;
			
			if (n == 0 && sum >= 10) {
				n = sum;
				sum = 0;
			}
		}

		cout << sum << "\n";
	}
}
