// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    string s;
    int cnt=0;
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\"') {
                if (cnt % 2 == 0)
                    cout << "``";
                else
                    cout << "''";
                cnt++;
            } else {
                cout << s[i];
            }
        }
        cout << "\n";
    }
}
