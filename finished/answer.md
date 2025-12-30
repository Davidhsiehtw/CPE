# 解答存放區
> 2.23.2025 完成三題 walkthrough
> 2.24.2025 完成自己寫 4 題
> 2.25.2025 自己寫一題+檢討＋go through 3 題
> 3.03.2025 完成一題 walkthrough!
> 3.05.2025 

[一顆星選集筆記 part 1 詳解](https://reurl.cc/A3WLXY)
[一顆星選集筆記 part 2 詳解](https://reurl.cc/4NDvYK)

```cpp
// Hardwood species
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n;
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	while (n--) {
		int sum = 0;
		map<string, int> mp;
		while (getline(cin, s) && s != "") {
			mp[s]++;
			sum++;
		}
		for (auto i : mp) {
			cout << i.first << " " << fixed << setprecision(4) << (double) i.second / sum * 100 << "\n";
		}
		if (n!=0)
		    cout << "\n";
	}
}
```


```cpp
// Train Swapping
#include <bits/stdc++.h>
using namespace std;
int main() {
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
```

```cpp
// 題目在這：https://onlinejudge.org/external/110/11005.pdf
// Python 詳解: https://blog.iddle.dev/public/2024/04/19/Python-UVa-11005-Cheapest-Base/
// C++ 詳解: https://yuihuang.com/uva-11005/
// 需熟悉 10 進位轉任意進位
// 需使用 map 紀錄
#include <bits/stdc++.h> // CPE 系統允許使用！要熟記
using namespace std;
int main() {
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

```

```cpp
// Rotating Sentences
/*
 * 要特別注意範例輸出的空格。複製貼上用游標一個個走訪便會理解
 * */

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str[100];
	int col = 0, row = 0;
	while (getline(cin, str[col])) {
	    row = max(row, (int) str[col].size()); // 轉置後
		col++; // 轉置後
	}

	// 測資
	// Rene Decartes once said,
	// "I think, therefore I am."
	for (int i = 0; i < row; i++) {
		for (int j = col - 1; j >= 0; j--) { // 長度 - 1
			// 當前的 row 值 (i.e. i 值) 大於 str[j]長度 補空白
			if (i >= str[j].size()) cout << " ";
			else cout << str[j][i];
		}
		cout << '\n';
	}
	return 0;
}
	/*
	 * 順序是 [n, 0], [n-1, 0], ... 輸出。頭逆時針90度看
	 *
	 * [0, 0], [0, 1], ...
	 * [1, 0], [1, 1], ...
	 * [2, 0], [2, 1], ...
	 * [n, 0], ......, [n, n]
	 *
	 * row 1   row 2   ...
	 * */
```

```cpp
// fibonaccimal base
/*
    這是指定長度，不合理
    int f[41] = {0, 1};
    for (int i = 1; f[i - 1] < 1e8; i++) {
        f[i] = f[i - 0] + f[i - 2];
    }
    16  從大到小挑出
    細節：費氏數列表示法要從 0 開始計，而忽略前面的 0 1
    // 16                        1 0 0 1 0 1 X X
    // f: [~0,000,000, ... , 21 13 8 5 3 2 1 1 0]
    // 7                           1 0 0 0 0 X X
    // f: [~0,000,000, ... , 21 13 8 5 3 2 1 1 0]
    // 這裡適合用動態陣列 vector，若用一般array無法不指定長度
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> f;
    int f1 = 1, f1 = 1, f0 = 0;
    while (f1 <= 1e8) {
        f1 = f1 + f0;
        f.push_back(f1);
        f-1 = f1;
        f0 = f2;
    }
    reverse(f.begin(), f.end());

    int N, n, check=-1;
    cin >> N;
    while (N--) {
        cin >> n; // n = 16
        int n1 = n;
        vector<int> ans;
        check=-1;
        for (int x : f) {
            if (n >= x) {
                n -= x;
                check = 0;
                ans.push_back(0);
            } else {
                if (check == 0) // 需適時寫 0
                    ans.push_back(0);
            }
        } 
        cout << n1 << " = ";
        for (int num : ans) cout << num; 
        cout << " (fib)" << "\n";
    } 
}
```


```cpp
// 參考：https://hackmd.io/@LukeTseng/H10nwBa3ex#3-Uva-673---Parentheses-Balance
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	getline(cin, s);	
    while (getline(cin, s)) {
        string t;
        bool ok = true;

        for (char c : s) {
            if (c == '(' || c == '[')
                t.push_back(c);
            else if (c == ')') {
                if (t.empty() || t.back() != '(') { ok = false; break; }
                t.pop_back();
            }
            else if (c == ']') {
                if (t.empty() || t.back() != '[') { ok = false; break; }
                t.pop_back();
            }
        }

        if (ok && t.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}

```

```cpp
// you-can-say-11
#include <iostream>
using namespace std;
int main() {
    string n;
    while (cin >> n) {
        if (n == "0") break;
        // TODO: 計算 (奇數位數的數字和 + 偶數位數的數字和) % 11 = 0
        // 解析出 n[0] 的數字，利用字元 ASCII 值的差得出
        // int n1 = n[0] - "0";
        int odd = 0, even = 0;
        for (int i = 0; i < n.size(); i++) {
            if (i % 2) odd += n[i] - '0'; // i = 1, 3, 5...
            else even += n[i] - '0';
        }
        if ((odd - even) % 11 == 0)
            cout << n << " is a multiple of 11.\n";
        else 
            cout << n << " is not a multiple of 11.\n";
    }
}
```

```cpp
// Flip Sort
// 解答：https://yuihuang.com/zj-a539/
#include <iostream>
using namespace std;

int a[1000];

int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++)
		    cin >> a[i];

		int ans = 0;
		for (int j = n; j > 0; j--) {
			for (int i = 0; i < j - 1; i++) {
				if (a[i] > a[i + 1]) {
					swap(a[i], a[i + 1]);
					ans++;
				}
			}
		}
		cout << "Minimum exchange operations : " << ans << "\n";
	}
}
```

```cpp
// A mid-summer nights dream
// 解答：https://yuihuang.com/zj-e606/
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    while (cin >> n){
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
		sort(a, a+n);
		int mid1 = a[(n-1)/2];
		int mid2 = a[n/2];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == mid1 || a[i] == mid2) ans++;
		}
		cout << mid1 << " " << ans << " " << mid2 - mid1 + 1 << "\n";
    }
    return 0;
}
```

```cpp
// Beat the Spread
// 解答：https://yuihuang.com/zj-c004/
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int n, s, d;
	int a, b;
	cin >> n;
	while (n--) {
		cin >> s >> d;

		// Let a > b
		// s = a + b
		// d = a - b
		// => s + d = 2a -> a = (s + d) / 2
		// => s - d = 2b -> b = (s - d) / 2

		// => b = a - d ; a = d + b
		// => s = d + 2b
		// => b = (s - d) / 2
		// => a = s - b
		b = (s - d) / 2; 
		a = s - b; 
		// CAVEAT: non-negative integers representing the sum and difference	
		if (s < d || (s + d) % 2) { // 也可以 (s - d) % 2
			cout << "impossible" << endl;
		}
		else if (a >= b) {
			cout << a << " " << b << endl;
		} else {
			cout << b << " " << a << endl;
		}
	}
}
```

```cpp
// Cola 模擬法、數值解
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	int cnt;
	while (cin >> n) {
		cnt = floor(1.5 * n);
		cout << cnt << endl;
	}
}
```

```cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	long long S, D; // 
	int cnt; // 計數人數

	while(cin >> S >> D) {
		cnt = S; // 初始人數
		D -= S;  // 初始天數
		while (D > 0) { // 6
			cnt++; 
			D -= cnt;
			// 錯在順序！
			// D -= cnt;
			// cnt++; 
		}
		cout << cnt << endl;
	}
}
	// 數字表示日期
	// 1      (ㄧ人)
	// 2 3    (二人)
	// 4 5 6  (三人)
	// =>  
	
	// 3 10
	// 1 2 3    (三人)
	// 4 5 6 7  (四人)
	// 8 9 10   (五人)
	
	// D -= cnt 後 cnt++，D -= cnt+1 後 cnt++
```
    
```cpp
// Jolly Jumpers
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	 
	// 陣列索引值為差值，存放的值為出現的次數，這存放資料的方式有一點點不直覺。
	// 這技巧有什麼名稱嗎？
	while (cin >> n) { // 4 1 4 2 3
		int pre, now;
		int d[n];
		for (int i = 0; i < n; i++) {
			d[i] = 0;
		}
		cin >> pre;
		for (int i = 1; i < n; i++) {
			cin >> now;
			d[abs(now - pre)]++;
			pre = now;
		}
		bool flag = true;
		for (int i = 1; i < n; i++) {
			if (d[i] != 1) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
	return 0;
}

// 我嘗試寫的
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int a[n]={0};
		int b[n+1]={0}; // b[0] 不處理 空著
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n-1; i++)
			b[abs(a[i] - a[i+1])]++;
	
		bool flag = true;
		for (int i = 1; i <= n-1; i++) {
			if (b[i] == 0) flag = false; 
		}
		if (flag) cout << "Jolly" << "\n";
		else cout << "Not jolly\n";
	}
}



```

```cpp
// The Hotel with Infinite Rooms
/*
 以S-3, D=10為例
       |
	   v
  cnt = 3, S = 7 (剩)
	   |
	   v
  cnt = 4, S = 3 (剩)
	   |
	   v
  cnt = 5, S = -2 (剩)
	   |
	   v
  迴圈結束
 * */
#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long S, D, cnt;
    while (cin >> S >> D){
        cnt = S;
        D -= S;
        while (D > 0){
            cnt++;
            D -= cnt;
			cout << "Current D: " << D << endl;
        }
        cout << cnt << "\n";
    }
    return 0;
}
```

```cpp
// What is the Probability?
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int S, N, K;
    double p;
    cin >> S;
    while (S--){
        cin >> N >> p >> K;
        if (p == 0) {
            cout << "0.0000\n";
            continue;
        }
        double first = pow(1.0 - p, K-1) * p;
        double r = pow(1.0 - p, N);
        cout << fixed << setprecision(4) <<
        first / (1.0 - r) << "\n";
    }
    return 0;
}
```

```cpp
#include <iostream>
#include <cstring>
using namespace std;
 
int main() {
	int pre, rear;
	// 5 1 4 2 -1 6
	int n; // 4 1 4 2 3
	int d[n];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			d[i] = 0;
		}
		cin >> pre;
		for (int i = 1; i < n; i++) {
			cin >> rear;          // 索引值代表差      [0] [1] [2] [3] 
			d[abs(rear - pre)]++; //             d[] = {0, 1, 1, 1};
			pre = rear;
		}
		bool flag = true;
		for (int i = 1; i < n; i++) {
			if (d[i] != 1) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
}
```

```cpp
// Doom's Day Algorithm 
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	// 2011 的 4/4, 6/6, 8/8, 10/10, 12/12, 5/9, 9/5, 7/11, 11/7, 1/10, 2/21
	// 3 月要心算。已知 2/21(Mon.)，則2/28(Mon.)、3/7也是(Mon.)
	// doom[0] = -1 是拿來佔位的，因為月份不會有0月，方便之後的運算。
    // 這裡採用 1-based indexing
	/*int doom[13] = {-1, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};*/
	int doom[13] = {-1, 10, 21, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12};

    // 另解，date[0] = Sunday，會比較好？
	string date[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	int n, m, d;	
	cin >> n;
	while (n--) {
		cin >> m >> d;
		int delta = (d - doom[m]) % 7;// -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7
		if (delta >= 0) {
			cout << date[delta] << endl;
		} else {
			cout << date[7 + delta] << endl;
		}
	}
	/*int DDD = -1 % 7;*/
	/*cout << DDD; //  輸出是-1*/
}


// 試著自己推一遍
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	// 2/21(Mon.) => 3/1(Tue.) => 3/7(Mon.)
	// 1-based indexing
	int doom[13] = {-1, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
	
	// 1-based indexing ?
	string date[] = {
		"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
	};
	
	int T, m, d;	
	cin >> T;
	while (T--) {
		cin >> m >> d;

		int delta = (d - doom[m]) % 7;
		if (delta < 0) {
			cout << date[delta + 7] << endl;
		} else {
			cout << date[delta] << endl;
		}
	}
}
// 推導:
		// delta > 0
		// 2 28
		// delta = (28 - 21) % 7 = 0
		// => date[delta]

		// delta < 0
		// 1 6
		// doom[1] = 10 (Mon.)
		// delta = (6 - 10) % 7 = -4 
		// date[delta + 7]

		// 1 31
		// doom[1] = 10 (Mon.)
		// delta = (31 - 10) % 7 = 0

		// delta < 0
		// 8 1
		// doom[8] = 8 (Mon.)
		// delta = 1 - 8 = -7 (往左 7 格 => 相對是往右 0 格)
		// date[delta + 7]
		// => date[0]
```

```cpp
// TEX QUOTES
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	string s;
	int cnt;
	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '\"') {
				if (cnt % 2 == 0) cout << "``";
				else cout << "''";
				cnt++;
			} else {
				cout << s[i];
			}
		}
		cout << "\n";
	}
	return 0;
}

// 某次練習這樣寫 寫得很醜 :(
#include <bits/stdc++.h>
using namespace std;
int main() {
	string line;
	int cnt = 1;
	// for loop line 定位到 " 換成 `` or '' 用 cnt 去評估
	while (getline(cin, line)) {
		for (char c : line) {
			if (c == '"' && cnt % 2) {
				cout << "``";
				cnt++;
			}
			else if (c == '"' && cnt % 2 == 0) {
				cout << "''";
				cnt++;
			}
			else
				cout << c;
			
		}
		cout << "\n";
	}
}
```



```cpp
// Decode the Mad man
// CPE 評測測資會有大寫字母，記得要 tolower
#include <iostream>
#include <map>
using namespace std;

int main() {
	string s[] = {
		"~!@#$%^&*()_+",
		"`1234567890-=",
		"qwertyuiop[]\\",
		"asdfghjkl;'",
		"zxcvbnm,./"
	};

	map<char, char> mp;
	for (int i = 0; i < 5; i++) {
		for (int j = 2; j < s[i].size(); j++)
			mp[s[i][j]] = s[i][j-2];
	}

	string S;
	while(getline(cin, S)) {
		for (int i = 0; i < S.size(); i++) {
		  char c = tolower(S[i]);
			if (c == ' ') cout << ' ';
			else cout << mp[c];
		}
		cout << "\n";
	}
}
```


```cpp
// What's Cryptanalysis
#include <vector> // STL 提供begin() end()，能用在 sort()
#include <iostream>
#include <algorithm>
using namespace std;

// 不符合 return 中的判斷式，則順序對調 ; 符合，則順序不變
bool cmp(pair<int, char> a, pair<int, char> b) {
    if (a.first != b.first) return a.first > b.first; // 大的在前。e.g., (5, 'A') > (3, 'B')
    else return a.second < b.second; // 字母小的在前，(3, 'A') 會排在 (3, 'B') 前。
}

int main() {
	pair<int, char> v[26]; // 另解 vector<pair<int, char>> v(26); 初始化方式相同
	for (int i = 0; i < 26; i++) {
		v[i] = {0, 'A' + i};
	}
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if ('A' <= s[i] && s[i] <= 'Z')
				v[s[i] - 'A'].first++;
			if ('a' <= s[i] && s[i] <= 'z')
				v[s[i] - 'a'].first++;
		}
	}
	sort(v, v + 26, cmp); // 另解 sort(v.begin(), v.end(), cmp);
	for (auto i: v) {
		if (i.first > 0) cout << i.second << " " << i.first << "\n";
	}
}
```

```cpp
// What's Cryptanalysis 寫法 2 by gpt4, 但這沒有比較簡單...
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<char, int> &a, const pair<char, int> &b) {
    if (a.second != b.second) return a.second > b.second; // 次數降序
    return a.first < b.first; // 字母升序
}

int main() {
    map<char, int> freq;
    int n;
    string s;

    cin >> n;
    getline(cin, s); // 吃掉換行符，避免影響 getline()

    while (n--) {
        getline(cin, s);
        for (char c : s) {
            if (isalpha(c)) { // 判斷是否是字母
                freq[toupper(c)]++; // 統一轉成大寫
            }
        }
    }

    // 轉換為 vector 排序
    vector<pair<char, int>> sorted_freq(freq.begin(), freq.end());
    sort(sorted_freq.begin(), sorted_freq.end(), cmp);

    // 輸出結果
    for (auto &[ch, count] : sorted_freq) {
        cout << ch << " " << count << "\n";
    }

    return 0;
}
```

```cpp
// Summing Digits
#include <iostream>
using namespace std;

// "This is the ugliest piece of recursive crap I've ever seen!" 🤬
int f(int n) {
	int sum = 0;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}

	if (sum < 10) return sum;
	else return f(sum);
}

// "This is the ugliest piece of recursive crap I've ever seen!" 🤬
int f2(int n) {
	int sum = 0;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}

	if (sum >= 10) return f(sum);
	else return sum;
}

// 如果 Linus Torvalds 來改寫，他會這樣寫
// Linus 一定會改成 迴圈版本，簡單俐落：
int f3(int n) {
    while (n >= 10) {  // 迴圈代替遞迴
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum; // 直接更新 n，不用遞迴
    }
    return n;
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) return 0;
		cout << f3(n) << endl;
	}
	return 0;
}
```

```cpp
// Rotating_Sentences
#include <iostream>
using namespace std;
string s[105];

int main() {
    int col = 0, row = 0;
    while (getline(cin, s[col])){
        row = max(row, (int)s[col].size());
        col++;
    }
    for (int i = 0; i < row; i++){
        for (int j = col; j > 0; j--){
            if (i >= s[j-1].size()) cout << " ";
            else cout << s[j-1][i];
        }
        cout << "\n";
    }

    /*for (int i = 0; i < row; i++){*/
    /*    for (int j = col-1; j >= 0; j--){*/
    /*        if (i >= s[j].size()) cout << " ";*/
    /*        else cout << s[j][i];*/
    /*    }*/
    /*    cout << "\n";*/
    /*}*/

    return 0;
}

// 這是嘗試推導的過程
/*int main() {*/
/*	string ss[3] = {*/
/*		"Rene Decartes once said,",*/
/*		"\"I think, therefore I am.\""*/
/*	};*/
/*	cout << ss[1][0] << ss[0][0] << endl;*/
/*	cout << ss[1][1] << ss[0][1] << endl;*/
/**/
/*	int row = 26;*/
/*	int col = 2;*/
/*	for (int i = 0; i < row; i++) {*/
/*		for (int j = col; j > 0; j--) {*/
/*			if (i >= ss[j-1].size()) cout << " ";*/
/*			else cout << ss[j-1][i];*/
/*			cout << ss[j-1][i];*/
/*		}*/
/*		cout << endl;*/
/*	}*/
/*} */


/*
Hi there.   
that's awesome.

tH
hi
a
tt
'h
se
 r
ae
w.
e
s
o
m
e
.

*/
```
