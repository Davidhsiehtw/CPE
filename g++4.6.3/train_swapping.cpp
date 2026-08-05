// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int L;
		cin >> L;
		int arr[L];
		int cnt = 0;
		for (int i = 0; i < L; i++)
			cin >> arr[i];
		
		// bubble sort
		for (int j = 0; j < L; j++) {
			for (int i = 0; i < L-1-j; i++) { // 3 2 1
				if (arr[i] > arr[i+1]) {
					// 可以用 swap() 替換 但 for loop 的索引也要跟著換
					int t = arr[i+1];
					arr[i+1] = arr[i];
					arr[i] = t;
					cnt++;
				}
			}
		}
		cout << "Optimal train swapping takes " << cnt << " swaps.\n";
	}
}
