// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);

    string s;
    while (cin >> s) {
        int a = atoi(s.c_str()); // 原本寫法 int a = stoi(s); g++4.6.3 不支援

        reverse(s.begin(), s.end());

        int b = atoi(s.c_str());

        if (isPrime(a)) {
            if (isPrime(b) && a != b)
                cout << a << " is emirp.\n";
            else
                cout << a << " is prime.\n";
        } else {
            cout << a << " is not prime.\n";
        }
    }
}



#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	string s;
	while (cin >> s) {
		int a = stoi(s);
		reverse(s.begin(), s.end());
		int b = stoi(s);
		
		if (isPrime(a)) {
			if (isPrime(b) && a != b)
				cout << a << " is emirp.\n";
			else
				cout << a << " is prime.\n";
		} else {
			cout << a << " is not prime.\n";
		}
	}
}
