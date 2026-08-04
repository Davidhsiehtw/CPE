/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*	int a, b;*/
/*	while (cin >> a >> b) {*/
/*		if (a == 0 && b == 0) break;*/
/*		double cnt = 0;*/
/*		for (int i = a; i <= b; i++) {*/
/*			double t = sqrt(i);*/
/*			if (t == int(t))*/
/*				cnt++;*/
/*		}*/
/*		cout << cnt << endl;*/
/*	}*/
/*}*/


/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int main() {*/
/*	int a, b;*/
/*	while (cin >> a >> b) {*/
/*		if (a == 0 && b == 0) break;*/
/*        int n1 = ceil(sqrt(a)); // NOTE:*/
/*        int n2 = sqrt(b);*/
/*        int cnt = 0;*/
/*        for (int i = n1; i <= n2; i++)*/
/*            cnt++;*/
/*        cout << cnt << endl;*/
/*	}*/
/*}*/


#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
        int n1 = ceil(sqrt(a)); // NOTE:
        int n2 = sqrt(b);
        cout << n2 - n1 + 1 << endl;
	}
}

