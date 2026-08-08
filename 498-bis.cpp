#include <bits/stdc++.h>
using namespace std;
string s;
int x;
vector <int> v;
int main() {
    while (cin >> x){
        cin.ignore(); // clear "\n"
        getline(cin, s);
        stringstream ss(s);
        v.clear();
        while (ss >> s)
            v.push_back(atoi(s.c_str()));
        v.pop_back();
        reverse(v.begin(), v.end());
        long long mul = 1;
        int ans = 0;
        for (int i = 0; i < v.size(); i++) { // i = degree ;  v[i] = coffi
            ans += v[i] * (i+1) * mul; // NOTE
            mul *= x;
        }
        cout << ans << "\n";
    }
}

/*
NOTE:
  f(x)  = 4 + 5x + 2x² + 3x³
  f'(x) = 5 + 4x + 9x²
  代入 x = 7：
    5 + 4(7) + 9(7²)
    = 5 + 28 + 441
    = 474
*/
