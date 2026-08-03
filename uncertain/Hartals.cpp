#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, N, P, h;
	cin >> T;
	while (T--) {
		cin >> N >> P;
		int a[N+1];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < P; i++) {
			cin >> h;
			for (int j = h; j <= N; j+=h) {
				a[j] = 1;
			}
		}
		
		for (int i = 6; i <= N; i+=7)
			a[i] = 0;
		for (int i = 7; i <= N; i+=7)
			a[i] = 0;
		
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += a[i];
		}
		cout << sum << endl;
	}
}

/*
2   T 組測資
14  模擬14天
3   3個政黨
3
4
8
100 模擬100天
4   4個政黨
12
15
25
40

*/


// 注意的點：
// 1 based index，所以排除週五週六，要用i=6, 7開始
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, P, h;
    cin >> T;
    while (T--) {
        cin >> N >> P;
        int a[N+1]; // a[i] = 1 代表第i天有罷工，a[i] = 0 代表第i天沒有罷工
        memset(a, 0, sizeof(a));
        for (int i = 0; i < P; i++){
            cin >> h;
            for (int j = h; j <= N; j+=h){
                a[j] = 1;
            }
        }

        // 排除週五週六，每七天循環，
        for (int i = 6; i <= N; i+=7)
            a[i] = 0;
        for (int i = 7; i <= N; i+=7)
            a[i] = 0;
        

        int sum = 0;
        for (int i = 1; i <= N; i++){
            sum += a[i];
        }
        cout << sum << "\n";
    }
    return 0;
}


// 宣告 int T, P, N, h; 將導致 NO OUTPUT，除非加上 ios::sync_with_stdio(0);
// 或是把順序改成 int T, N, P, h;，至於為什麼連 Claude Sonnet 都不知道
#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, P, N, h;
	cin >> T;
	while (T--) {
		cin >> N >> P;
		int a[N+1];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < P; i++) {
			cin >> h;
			for (int j = h; j <= N; j+=h)
				a[j] = 1;
		}
		
		for (int i = 6; i <= N; i+=7)
			a[i] = 0;
		for (int i = 7; i <= N; i+=7)
			a[i] = 0;
		
		int sum=0;
		for (int i = 1; i <= N; i++) {
			sum += a[i];
		}
		cout << sum << endl;
	}
	
}