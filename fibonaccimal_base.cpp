// 這題不能加上 ios::sync_with_stdio(0); 因為會 WA，原因不明
// 並且最後不能使用 "\n" 只能使用 endl，否則 WA，原因不明
#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> f;
	int f0 = 0, f1 = 1, f2 = 1;
	while (f2 <= 1e8) {
		f2 = f1 + f0;
		f.push_back(f2);
		f0 = f1;
		f1 = f2;
	}
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		cout << m << " = ";
		bool preone = false;
		for (int i = f.size()-1; i >= 0; i--) { // {..., 13, 8, 5, 3, 2, 1}
			if (m >= f[i]) {
				cout << "1";
				m -= f[i];
				preone = true;
			} else if (preone) {
				cout << "0";
			}
		}
		cout << " (fib)" << endl;
	}
}

    /*f.push_back(0);*/
    /*f.push_back(1);*/
// g++4.6.3 AC
// 耗時 70 min @ May 17
// 第二次嘗試，耗 ~30m





#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> f;
	int f0 = 0, f1 = 1, f2 = 1;
	while (f2 <= 1e8) {
		f2 = f1 + f0;
		f.push_back(f2);
		f0 = f1;
		f1 = f2;
	}
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m; // 17
		cout << m << " = ";
		bool preone = false;
		for (int i = f.size()-1; i >= 0; i--) { // {...,13,8,5,3,2,1}
			if (m >= f[i]) { 
				m -= f[i]; // 17-=13 -> 4
				cout << "1";
				preone = true;
			} else if (preone) {
				cout << "0";
			}
		}
		cout << " (fib)\n";
	}
}