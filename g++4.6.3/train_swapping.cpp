// TODO: 瘋狂程設要測
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        int cnt = 0;
        for (int i = 0; i < N-1; i++) {     // 若1 3 2，只要檢查 2 次，即 N-1
            for (int j = i+1; j < N; j++) { // i+1 指右邊那格，但要小於 N，不能出界
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                    cnt++;
                }
            }
        }
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }
}




// BAD
// g++4.6.3 AC
/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*	ios::sync_with_stdio(0);*/
/*	int T;*/
/*	cin >> T;*/
/*	while (T--) {*/
/*		int L;*/
/*		cin >> L;*/
/*		int arr[L];*/
/*		int cnt = 0;*/
/*		for (int i = 0; i < L; i++)*/
/*			cin >> arr[i];*/
/**/
/*		// bubble sort*/
/*		for (int j = 0; j < L; j++) {*/
/*			for (int i = 0; i < L-1-j; i++) { // 3 2 1*/
/*				if (arr[i] > arr[i+1]) {*/
/*					// 可以用 swap() 替換 但 for loop 的索引也要跟著換*/
/*					int t = arr[i+1];*/
/*					arr[i+1] = arr[i];*/
/*					arr[i] = t;*/
/*					cnt++;*/
/*				}*/
/*			}*/
/*		}*/
/*		cout << "Optimal train swapping takes " << cnt << " swaps.\n";*/
/*	}*/
/*}*/
