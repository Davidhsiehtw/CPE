// g++4.6.3 AC

// 題目：https://onlinejudge.org/external/110/11005.pdf
// Python 詳解: https://blog.iddle.dev/public/2024/04/19/Python-UVa-11005-Cheapest-Base/
// C++ 詳解: https://yuihuang.com/uva-11005/
// 需熟悉 10 進位轉任意進位
// 需使用 map 紀錄

#include <bits/stdc++.h> 
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int T, cost, n, x;
	cin >> T;
	for (int Case = 1; Case <= T; Case++) {
	    if (Case > 1) cout << "\n"; /** CAVEAT: 輸出格式要小心 */
		std::map<int, int> mp;
		for (int i = 0; i < 36; i++) {
			cin >> cost;
			mp[i] = cost;
		}
		cout << "Case " << Case << ":\n";
		cin >> n;
		while (n--) {
			int mn = INT_MAX;
			cin >> x;
			cout << "Cheapest base(s) for number " << x << ":";
			map<int, int> ans; // 紀錄每筆測資 x 所有進制的成本，之後挑最小的
			for (int i = 2; i <= 36; i++) {
				int temp = x; /** CAVEAT: 卡在這：每次 x 都要設定。 */
				cost = 0;
				while (temp > 0) { /** CAVEAT: 卡在這：變數誤用(變數沒改乾淨)。n、x、temp 之間關係要清楚 */
					cost += mp[temp % i];
					temp /= i;
				}
				// 紀錄2~36進制的成本，後面再與 mn 做比較
				ans[i] = cost;		// ans[2] = 24
				mn = min(cost, mn); // mn = min(24, MAX)
			}
			// outout:
			for (int i = 2; i <= 36; i++)
			    if (ans[i] == mn) cout << " " << i;
			cout << "\n";
		}
	}
}
