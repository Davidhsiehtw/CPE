#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    string B;
    int I;

    while (cin >> I) {
        if (I == 0) break;
        int P = 0;
        B="";

        while (I > 0) {
            if (I % 2 == 1) P++;
            cout << "P=" << P << "\n";
            B += '0' + (I % 2);
            I = I >> 1; // 10 -> 5 -> 2 -> 1
        }

        reverse(B.begin(), B.end());
        cout << "The parity of " << B << " is " << P << " (mod 2)." << "\n";
    }
}
