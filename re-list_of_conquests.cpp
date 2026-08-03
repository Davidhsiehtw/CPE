#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    string s;
    map<string, int> mp;
    cin >> n;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        stringstream ss(s);
        ss >> s;
        mp[s]++;
    }
    map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}
