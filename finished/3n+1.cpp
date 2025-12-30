/**
範例輸入 #1
1 10
10 1
100 200
201 210
900 1000

範例輸出 #1
1 10 20
10 1 20
100 200 125
201 210 89
900 1000 174

* 
* 
*/

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int i, j;
	while (cin >> i >> j) {
		int mx = 0;
		for (int n = min(i, j); n <= max(i, j); n++) {
			int n1 = n;
			int cnt = 1;
			while (n1 != 1) {
				if (n1 % 2) n1 = 3 * n1 + 1;
				else
					n1 /= 2;
				cnt++;
			}
	       	mx = max(mx, cnt);
		}
		cout << i << " " << j << " " << mx << "\n";
	}
	return 0;
}
