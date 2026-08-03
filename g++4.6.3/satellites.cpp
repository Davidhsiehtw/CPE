// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359 // 忘記 M_PI 可以這樣寫
#define DEG2RAD(theta)(theta)*(M_PI / 180.0)

int main() {
	const double r = 6440.0;
	double s, a, arc, chord;
	string str;
	while (cin >> s >> a >> str) {
		if (str == "min")
			a /= 60.0;
		arc = 2*M_PI*(r+s) * a / 360.0;
		chord = 2 * (r+s) * sin(DEG2RAD(a/2.0));
		printf("%.6f %.6f\n", arc, chord);		
	}
}


// 多處理了 edge case，不過 CPE 不用
// #include <bits/stdc++.h>
// using namespace std;
// #define DEG2RAD(theta) ((theta) * M_PI / 180.0)
// int main() {
//     string str;
//     double s, a, arc, chord;
//     double R = 6440.0;
//     while (cin >> s >> a >> str) {
//         if (str == "min")
//             a /= 60.0;
//         if (a > 180) // 不會有大於360度的測資
//             a = 360 - a;
//         arc = 2 * M_PI * (s + R) * a / 360.0;
//         chord = 2 * (s + R) * sin(DEG2RAD(a) / 2.0);
//         printf("%.6f %.6f\n", arc, chord);
//     }
// }

// 15:21

/*
 
500 30 deg
700 60 min
200 45 deg

*/



