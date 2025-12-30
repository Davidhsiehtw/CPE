/*
 * 已訂正
 * */

#include <iostream>
#include <sstream>
using namespace std;

int main() {
	// 0123
	// Love
	// cout << s[3] << s[2] << s[1] << s[0];
	string s;
	while (getline(cin, s)) {
		istringstream ss(s); // 卡在 ss >> s，以及宣告
		while (ss >> s) {
			for (int i = 0; i < s.length(); i++)
			    cout << s[s.length() - 1 - i];
			cout << " "; 
		}
		cout << "\n"; 
	}
}

/*
I love you.
You love me.
We're a happy family.

I evol .uoy
uoY evol .em
er'eW a yppah .ylimaf
*/
