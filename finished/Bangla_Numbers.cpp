// 更好的解法: https://yuihuang.com/zj-a741/
// 細節說明: https://czone6.notion.site/10101-Bangla-Numbers-39f8436d81cf49b6ba5d0e2c4a32a467
// 太多 branch 效能很爛
#include <iostream>
using namespace std;

#define ll long long

int a[] = {10000000, 100000, 1000, 100};
string s[] = {"kuti", "lakh", "hajar", "shata"};
string ans;

void slove2(ll N) {
	if (N >= a[0]) {
		slove2(N / a[0]);
		ans += " " + s[0];
		N %= a[0];
	}

	for (int i = 0; i < 4; i++) {
		// if (N / a[i] > 0) 或 if (N >= a[i]) 都可以？
		if (N >= a[i]) {
			ans += " " + to_string(N / a[i]) + " " + s[i];
		}
		N %= a[i];
	}
	if (N > 0) ans += " " + to_string(N);
}

int main() {
	ll N;
	int Case = 1;
	while (cin >> N) {
		cout <<    Case++<< ".";
		if (N == 0) cout << " 0\n";
		else slove2(N);
		cout << ans << "\n";
		ans="";
	}
	return 0;
}

void slove(ll N) {
	/*
	 * Too many branches, BAD performace.
	 * */
	if (N >= a[0]) {
		slove(N / a[0]);
		ans += "kuti ";
		N %= a[0];
	}
	// N = N - (N / a[0]) * a[0]; // bad

	// N=23764，若夠除，就繼續往下除a[1] a[2] a[3] 不夠除就留下數字。
	for (int i = 1; i < 4; i++) {
		if (N >= a[i]) {
			if (i == 1) {
			    ans += to_string(N / a[1]) + " lakh ";
			} else if (i == 2) {
			    ans += to_string(N / a[2]) + " hajar ";
			} else if (i == 3) {
			    ans += to_string(N / a[3]) + " shata ";
			}
			N %= a[i];
		}
	}
	if (N > 0) ans += to_string(N) + " ";
}

/*
some test case:
460000409000
467800456780
23764
45897458973958
0

460000409000
467000408900
467800456780

100000000000000 X
999999999999999
0
輸出
1. 46 hajar kuti 4 lakh 9 hajar
2. 46 hajar 7 shata kuti 4 lakh 8 hajar 9 shata
3. 46 hajar 7 shata 80 kuti 4 lakh 56 hajar 7 shata 80
4. 1 kuti kuti
5. 9 kuti 99 lakh 99 hajar 9 shata 99 kuti 99 lakh 99 hajar 9 shata 99
6. 0

Sample Output
1. 23 hajar 7 shata 64
2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58
*/
