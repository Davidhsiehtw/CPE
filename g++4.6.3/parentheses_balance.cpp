
// g++4.6.3 AC
// string 沒有 back() pop_back() 實作，所以改用 vector
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);

        vector<char> st;
        bool ok = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(' || c == '[') {
                st.push_back(c);
            }
            else if (c == ')') {
                if (st.empty() || st.back() != '(') {
                    ok = false;
                    break;
                }
                st.pop_back();
            }
            else if (c == ']') {
                if (st.empty() || st.back() != '[') {
                    ok = false;
                    break;
                }
                st.pop_back();
            }
        }

        if (ok && st.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}


















/*
必須知道：
string s;
- s.size()
- s.push_back(char) 同 stack 的 push()
- s.pop_back(char)  同 stack 的 pop()
- s.back()  	    同 stack 的 top()
*/

// 參考：https://hackmd.io/@LukeTseng/H10nwBa3ex#3-Uva-673---Parentheses-Balance







#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
	string s;
	getline(cin, s);	
    while (getline(cin, s)) {
        string t;
        bool ok = true;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '[')
                t.push_back(c);
            else if (c == ')') {
                if (t.empty() || t.back() != '(') { ok = false; break; }
                t.pop_back();
            }
            else if (c == ']') {
                if (t.empty() || t.back() != '[') { ok = false; break; }
                t.pop_back();
            }
        }
        if (ok && t.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}



        
        // for (char c : s) {
        //     if (c == '(' || c == '[')
        //         t.push_back(c);
        //     else if (c == ')') {
        //         if (t.empty() || t.back() != '(') { ok = false; break; }
        //         t.pop_back();
        //     }
        //     else if (c == ']') {
        //         if (t.empty() || t.back() != '[') { ok = false; break; }
        //         t.pop_back();
        //     }
        // }
