// g++4.6.3 AC

// GPT 提供的簡潔寫法
#include <bits/stdc++.h>
using namespace std;

char mirror(char c) {
    switch (c) {
        case 'A': return 'A';
        case 'E': return '3';
        case 'H': return 'H';
        case 'I': return 'I';
        case 'J': return 'L';
        case 'L': return 'J';
        case 'M': return 'M';
        case 'O': return 'O';
        case 'S': return '2';
        case 'T': return 'T';
        case 'U': return 'U';
        case 'V': return 'V';
        case 'W': return 'W';
        case 'X': return 'X';
        case 'Y': return 'Y';
        case 'Z': return '5';
        case '1': return '1';
        case '2': return 'S';
        case '3': return 'E';
        case '5': return 'Z';
        case '8': return '8';
        default: return ' ';
    }
}

int main() {
	ios::sync_with_stdio(0);
    string s;
    while (cin >> s) {
        bool isPal = true;
        bool isMir = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[s.size()-1-i])
                isPal = false;

            if (mirror(s[i]) != s[s.size()-1-i])
                isMir = false;
        }

        if (!isPal && !isMir)
            cout << s << " -- is not a palindrome.\n\n";
        else if (isPal && !isMir)
            cout << s << " -- is a regular palindrome.\n\n";
        else if (!isPal && isMir)
            cout << s << " -- is a mirrored string.\n\n";
        else
            cout << s << " -- is a mirrored palindrome.\n\n";
    }
}