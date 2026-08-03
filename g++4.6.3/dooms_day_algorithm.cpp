// g++4.6.3 AC
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	// 2/21(Mon.) => 3/1(Tue.) => 3/7(Mon.)
	// 1-based indexing
	int doom[13] = {-1, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12}; 
	
	// 1-based indexing ?
	string date[7] = {
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
