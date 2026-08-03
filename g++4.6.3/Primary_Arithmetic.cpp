// g++4.6.3 AC
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
                /*
                    GPT:
                    假設不是十進位加法，而是做：
                    99 + 99 + 99
                    一次加三個數字。
                    此時：
                    t = 9 + 9 + 9 + carry;
                    可能變成 27
                    那麼 carry = t / 10，得到 carry = 2
                    這才是正確的進位。
                */
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
