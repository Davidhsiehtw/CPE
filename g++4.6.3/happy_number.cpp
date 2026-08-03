// g++4.6.3 AC @ Apr 28 12:47
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n, Case = 1;
    int N;
    int sum = 0;
    cin >> n;
    while (n--) {
        cin >> N;
        int start = N;
        sum = N;
        set<int> seen;
        bool isHappy = false;

        while (1) {
            N = sum;
            sum = 0;
            while (N) {
                int digit = N % 10;
                N /= 10; 
                sum += digit * digit;
            } 
            /*cout << sum << endl;  // 現在一定會執行*/
            if (sum == 1) {
                isHappy = true;
                break;
            } 

            /*if (sum == 4) {*/
            /*    isHappy = false;*/
            /*    break;*/
            /*}*/

            if (seen.count(sum)) {
                isHappy = false;
                break;
            }
            seen.insert(sum);

        }
        if (isHappy)
            cout << "Case #" << Case++ << ": "<< start << " is a Happy number.\n"; 
        else 
            cout << "Case #" << Case++ << ": " << start << " is an Unhappy number.\n";
    }
}

