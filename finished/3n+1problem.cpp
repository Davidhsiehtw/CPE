#include <iostream>
using namespace std;

int main() {
	int a, b, count, curr_max = 0;
	while (cin >> a >> b) {
		for (int i = min(a, b); i <= max(a, b); i++) {
			int n = i;
			count = 1;
			while(n != 1) {
				if (n % 2 == 1)
					n = 3 * n + 1;
				else
					n = n / 2;
				count++;
			}
			curr_max = max(count, curr_max);
		}
		cout << a << " " << b << " " << curr_max << "\n";
		curr_max = 0;
	}

	return 0;
}


/*#include <iostream>*/
/*using namespace std;*/
/*int main() {*/
/**/
/*}*/


// #include <iostream>
// using namespace std;
// int main() {
// 	int a, b, count, curr_max = 0;
// 	while (cin >> a >> b) {
// 		for (int i = min(a, b); i <= max(a, b); i++) {
// 			int n = i;
// 			count = 1;
// 			while(n != 1) {
// 				if (n % 2 == 1)
// 					n = 3 * n + 1;
// 				else
// 					n = n / 2;
// 				count++;
// 			}
// 			curr_max = max(count, curr_max);
// 		}
// 		cout << a << " " << b << " " << curr_max << "\n";
// 		curr_max = 0;
// 	}
// 	return 0;
// }
