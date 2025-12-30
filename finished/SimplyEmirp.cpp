#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	string N;

	while (cin >> N) {
		int a = stoi(N);
		reverse(N.begin(), N.end());
		int b = stoi(N);

		if (isPrime(a)) {
			if (a != b && isPrime(b))
				cout << a << " is emirp.\n";
			else
				cout << a << " is prime.\n";
		}
		else {
			cout << a << " is not prime.\n";
		}

		// WRONG!
		// if (a != b && isPrime(a) && isPrime(b)) cout << a << " is emirp.\n";
		// else if (isPrime(a) && !isPrime(b)) cout << a << " is prime.\n";
		// else if (!isPrime(a)) cout << a << " is not prime.\n";
	}
}
