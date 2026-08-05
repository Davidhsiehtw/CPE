/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*	int a, b;*/
/*	while (cin >> a >> b) {*/
/*		if (a == 0 && b == 0) break;*/
/*		double cnt = 0;*/
/*		for (int i = a; i <= b; i++) {*/
/*			double t = sqrt(i);*/
/*			if (t == int(t))*/
/*				cnt++;*/
/*		}*/
/*		cout << cnt << endl;*/
/*	}*/
/*}*/


/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*	int a, b;*/
/*	while (cin >> a >> b) {*/
/*		if (a == 0 && b == 0) break;*/
/*        int n1 = ceil(sqrt(a)); // NOTE:*/
/*        int n2 = sqrt(b);*/
/*        int cnt = 0;*/
/*        for (int i = n1; i <= n2; i++)*/
/*            cnt++;*/
/*        cout << cnt << endl;*/
/*	}*/
/*}*/


// 題目：求出 a 與 b 之間 (含) 有幾個完全平方數。i.e. [a, b]
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
           // NOTE: int n1 = sqrt(a); 會是無條件向下取整數
           // 因為平方函數在正數範圍是遞增的，所以：
           //   a ≤ x²≤ b
           // 兩邊開平方：
           //   √a ≤ x ≤ √b
           // 現在問題變成：
           // [sqrt(a), sqrt(b)] 這個範圍裡，有多少個整數？
           // 舉個例子，a = 10
           // 則，√10 = 3.162...
           // x ≥ 3.162...，那麼合法的最小整數就是 4
           // 所以下界應該是 ceil(sqrt(a))
           // 同理上界 √20 = 4.472..
           // x ≤ 4.472，則 x = 4
	       int n1 = ceil(sqrt(a));
	       int n2 = sqrt(b);
	       cout << n2 - n1 + 1 << endl;
	}
}
