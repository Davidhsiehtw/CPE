// 好的解法: https://yuihuang.com/zj-a741/   -> 他手寫 num2str() 或許可考慮這樣寫
// 細節說明: https://czone6.notion.site/10101-Bangla-Numbers-39f8436d81cf49b6ba5d0e2c4a32a467

// g++4.6.3 AC
// GPT code :https://chatgpt.com/c/69c4e315-13a4-8324-a274-89adb56ce188
#include <bits/stdc++.h>
using namespace std;

int Bangla[4] = {10000000, 100000, 1000, 100};
string s[4] = {"kuti", "lakh", "hajar", "shata"};
string ans;
#define ll long long
string itos(ll x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
void solve(ll n) {
    if (n >= Bangla[0]) {
        solve(n / Bangla[0]);     // ⚠️ 這題其實需要 recursion（原本寫錯）
        ans += " " + s[0];
        n %= Bangla[0];
    }
    for (int i = 1; i < 4; i++) {   // ⚠️ kuti 已經處理過，從 1 開始
        if (n >= Bangla[i]) {
            ans += " " + itos(n / Bangla[i]) + " " + s[i];
            n %= Bangla[i];
        }
    }
    if (n > 0)
        ans += " " + itos(n);
}
int main() {
    ios::sync_with_stdio(0);
    ll n;
    int Case = 1;
    while (cin >> n) {
		// 注意雞巴格式
        if (Case < 10) cout << "   " << Case++ << ".";
        else cout << "  " << Case++ << ".";
        if (n == 0) {
            cout << " 0\n";
            continue; // 注意記得 continue
        }
        solve(n);
        cout << ans << "\n";
        ans = "";
    }
}


// to_string 不能用
// #include <bits/stdc++.h>
// using namespace std;
// int Bangla[4] = {10000000, 100000, 1000, 100};
// string s[4] = {"kuti", "lakh", "hajar", "shata"};
// string ans;
// #define ll long long
// void solve(ll n) {
// 	if (n > Bangla[0]) {
//         ans += " " + s[0];
//         n %= Bangla[0];
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		if (n >= Bangla[i]) { 
// 			ans += " " + to_string(n / Bangla[i]) + " " + s[i]; // 原本是用 to_string
// 		}
// 		n %= Bangla[i];
// 	}
// 	if (n > 0)
// 		ans += " " + to_string(n);
// }
// int main() {
// 	ios::sync_with_stdio(0);
// 	ll n;
// 	int Case = 1;
// 	while (cin >> n) {
// 		// 注意雞巴格式
// 		if (Case < 10) cout << "   " << Case++ << "."; 
// 		else cout << "  " << Case++ << ".";
// 		if (n == 0) {
// 			cout << " 0\n";
// 			continue; 
// 		}
// 		solve(n);
// 		cout << ans << "\n";
// 		ans = "";
// 	}
// }
