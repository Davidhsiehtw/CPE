/*已 walkthrough 題目與解答*/
/*已自己寫過+檢討*/

#include <iostream>
using namespace std;

int main() {
	unsigned int x, y; // 123 456
	while (cin >> x >> y) {
    if (x == 0 && y == 0) break;
		int carry = 0;
		int cnt = 0;
		while (x > 0 || y > 0) {   // 錯在 || 寫成 && 
			int t = x % 10 + y % 10 + carry;
			if (t >= 10) {
				cnt++;
				carry = t / 10;
			} else {
				carry = 0;
			}
			x /= 10;
			y /= 10;
		}
	
		if (cnt == 0) {
			cout << "No carry operation." << endl;
		} else if (cnt == 1) {
			cout << "1 carry operation." << endl;
		} else {
			cout << cnt <<" carry operations." << endl;
		}
	}
	return 0;
}
