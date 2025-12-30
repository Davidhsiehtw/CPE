// d255: 11417 – GCD
#include <bits/stdc++.h>
using namespace std;


int GCD(int x, int y) {
	while (true) {
		x = x % y;
		if (x == 0) break;
		y = y % x;
		if (y == 0) break;
	}
	return x + y;
}

int main() {
	int N, G;
	while (cin >> N && N) {
		G = 0;
		for (int i=1; i < N; i++)
			for (int j = i+1; j <= N; j++)
				G += GCD(i, j);
		cout << G << endl;
	}
}



// Die Game
/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/**/
/*int func(string s, int cnt = 0) {*/
/*	int total = 0;*/
/*	for (int i = 0; i < s.length(); i++)*/
/*		total = s[i] - '0';*/
/**/
/*	cnt++;*/
/*	if (total == 9)*/
/*		return cnt;*/
/*	else if (total < 9)*/
/*		return 0;*/
/*	else*/
/*		return func(to_string(total), cnt);*/
/*}*/
/**/
/*int main() {*/
/*	int n;*/
/*	string s;*/
/**/
/*	while (cin >> n) {*/
/*		if (n==0) break;*/
/*		map<string, int> mp;*/
/*		mp["top"] = 1;*/
/*		mp["north"] = 2;*/
/*		mp["west"] = 3;*/
/*		mp["east"] = 4;*/
/*		mp["south"] = 5;*/
/*		mp["bottom"] = 6;*/
/**/
/*		while (n--) {*/
/*			cin >> s;*/
/*			if (s == "north") {*/
/*				int t = mp["north"];*/
/*				mp["north"] = mp["top"];*/
/*				mp["top"] = mp["south"];*/
/*				mp["south"] = mp["bottom"];*/
/*				mp["bottom"] = t;*/
/*			}*/
/*			if (s == "east") {*/
/*				int t = mp["east"];*/
/*				mp["east"] = mp["top"];*/
/*				mp["top"] = mp["west"];*/
/*				mp["west"] = mp["bottom"];*/
/*				mp["bottom"] = t;*/
/*			}*/
/*			if (s == "west") {*/
/*				int t = mp["west"];*/
/*				mp["west"] = mp["top"];*/
/*				mp["top"] = mp["east"];*/
/*				mp["east"] = mp["bottom"];*/
/*				mp["bottom"] = t;*/
/*			}*/
/*			if (s == "south") {*/
/*				int t = mp["south"];*/
/*				mp["south"] = mp["top"];*/
/*				mp["top"] = mp["north"];*/
/*				mp["north"] = mp["bottom"];*/
/*				mp["bottom"] = t;*/
/*			}*/
/*		}*/
/*		cout << mp["top"] << endl;*/
/*	}*/
/*}*/



// But not quite conquer!
/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*	int n, m;*/
/*	while (cin >> n >> m) {*/
/*		vector<int> a;*/
/*		bool boring = false;*/
/*		if (n == 0 || m == 0) boring = true;*/
/*		else {*/
/*			a.push_back(n);*/
/*			while (n > 1) {*/
/*				if (n % m == 0) {*/
/*					n /= m;*/
/*					a.push_back(n);*/
/*				} else {*/
/*					boring = true;*/
/*					break;*/
/*				}*/
/*			}*/
/*		}*/
/*		if (boring)*/
/*			cout << "Boring!" << "\n";*/
/*		else {*/
/*			for (auto i : a) cout << i << " ";*/
/*			cout << "\n";*/
/*		}*/
/*	}*/
/*}*/


// All you need is Love
/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int mygcd(int x, int y) {*/
/*	while (true) {*/
/*		x = x % y;*/
/*		if (x == 0) break;*/
/*		y = y % x;*/
/*		if (y == 0) break;*/
/*	}*/
/*	return x + y;*/
/*}*/
/*int main() {*/
/*	// Binary to Decimal OK*/
/*	// GCD 找最大公因數*/
/*	string S1, S2;*/
/*	int N;*/
/*	cin >> N;*/
/*	for (int Case = 1; Case <= N; Case++) {*/
/*		cin >> S1 >> S2; // S1 = "11000"*/
/*		int n1 = 0, n2 = 0;*/
/*		for (int i = 0; i < S1.size(); i++) {*/
/*			n1 = n1 << 1;*/
/*			n1 += S1[i] - '0';*/
/*		}*/
/*		for (int i = 0; i < S2.size(); i++) {*/
/*			n2 = n2 << 1;*/
/*			n2 += S2[i] - '0';*/
/*		}*/
/*		cout << "Pair #" << Case;*/
/*		if (mygcd(n1, n2) > 1) cout << ": All you need is love!\n";*/
/*		else cout << ": Love is not all you need!\n";*/
/*	}*/
/*}*/


/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*    int n1 = 0;*/
/*    string S1 = "11000";*/
/*    for (int i = 0; i < S1.size(); i++) {*/
/*        n1 = n1 << 1;*/
/*        n1 += S1[i] - '0';*/
/*    }*/
/*    cout << n1 << "\n";*/
/*}*/






// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	int T;
// 	cin >> T;
// 	while (T--) {
// 		int L;
// 		cin >> L;
// 		int arr[L];
// 	}
// }




// Hardwood species
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	string s;
// 	int n;
// 	cin >> n;
// 	getline(cin, s);
// 	getline(cin, s);
// 	while (n--) {
// 		int sum = 0;
// 		map<string, int> mp;
// 		while (getline(cin, s) && s != "") {
// 			mp[s]++;
// 			sum++;
// 		}
// 		for (auto i : mp) {
// 			cout << i.first << " " << fixed << setprecision(4) << (double) i.second / sum * 100 << "\n";
// 		}
// 		cout << "\n";
// 	}
// }
