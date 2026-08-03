// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int n;
	string dir;
	map<string, int> mp;
	while (cin >> n) {
		mp["top"] = 1;
		mp["north"] = 2;
		mp["west"] = 3;
		mp["east"] = 4;
		mp["south"] = 5;
		mp["down"] = 6; 
		for (int i = 0; i < n; i++) {
			cin >> dir;
			if (dir == "north") { // OK
				int t = mp["top"];
				mp["top"] = mp["south"];
				mp["south"] = mp["down"];
				mp["down"] = mp["north"];
				mp["north"] = t;
			}
			else if (dir == "east") { // OK
				int t = mp["top"];
				mp["top"] = mp["west"];
				mp["west"] = mp["down"];
				mp["down"] = mp["east"];
				mp["east"] = t;
			}
			else if (dir == "south") { // OK
				int t = mp["top"];
				mp["top"] = mp["north"];
				mp["north"] = mp["down"];
				mp["down"] = mp["south"];
				mp["south"] = t;
			}
			else if (dir == "west") {  // OK
				int t = mp["top"];
				mp["top"] = mp["east"];
				mp["east"] = mp["down"];
				mp["down"] = mp["west"];
				mp["west"] = t;
			}
		}
		if (n!= 0) cout << mp["top"] << "\n";
	}
}