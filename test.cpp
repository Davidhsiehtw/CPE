#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
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
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}



/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*    int n; */
/*    cin>>n;*/
/*    map<string, int> count;*/
/*    string in;*/
/**/
/*    getline (cin, in);*/
/*    while (n--) {*/
/*        getline(cin, in);*/
/*        stringstream inn(in);*/
/*        inn>>in;*/
/*        count[in]++;*/
/*    }*/
/**/
/*    for (auto i=count.begin(); i!=count.end(); i++) {*/
/*        cout << i->first << " " << i->second <<"\n";*/
/*    }*/
/*    return 0;*/
/*}*/
