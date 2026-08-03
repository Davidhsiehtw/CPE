// 嘗試重寫 @ May 21 12:22
#include <bits/stdc++.h>
using namespace std;

int mp[256][11];

int main() {
	int tmp[][11] = {
		{0,0,1,1,1,0,0,1,1,1,1}, //c
		{0,0,1,1,1,0,0,1,1,1,0}, //d
		{0,0,1,1,1,0,0,1,1,0,0}, //e
		{0,0,1,1,1,0,0,1,0,0,0}, //f
		{0,0,1,1,1,0,0,0,0,0,0}, //g
		{0,0,1,1,0,0,0,0,0,0,0}, //a
		{0,0,1,0,0,0,0,0,0,0,0}, //b
		{0,0,0,1,0,0,0,0,0,0,0}, //C
		{0,1,1,1,1,0,0,1,1,1,0}, //D
		{0,1,1,1,1,0,0,1,1,0,0}, //E
		{0,1,1,1,1,0,0,1,0,0,0}, //F
		{0,1,1,1,1,0,0,0,0,0,0}, //G
		{0,1,1,1,0,0,0,0,0,0,0}, //A
		{0,1,1,0,0,0,0,0,0,0,0} //B
	};
	
	// map 按鍵位置
	// mp['c'][0~10] = 0 or 1;
	// mp['d'][0~10] = 0 or 1;
	string notes = "cdefgabCDEFGAB";
	for (int i = 0; i < notes.size(); i++) {
		for (int j = 1; j <= 10; j++)
			// 假設 notes[i] = 'c'，它是字元，但在 C/C++ 裡本質上其實是整數，(int)'c' == 99
			// mp['c'][3] 等價於 mp[99][3]，因此第一維必須夠大，能覆蓋所有 ASCII 字元。
			// ASCII 範圍：0-127，而很多人會直接開 256
			// 原因：方便、保證所有 extended ASCII 都能放、記憶體很小，根本不在乎
			mp[notes[i]][j] = tmp[i][j]; 
	}
	
	string s;
	int t;
	cin >> t;
	getline(cin, s); // clear buffer
	while (t--) {
		getline(cin, s);
		int cnt[11]={0};
		int a[11]={0}; // 紀錄當前按下的
		for (int i = 0; i < s.size(); i++) { // cdefgab
			for (int j = 1; j <= 10; j++) { // 'c'
				if (mp[s[i]][j]) {
					if (!a[j]) { // 若當前沒被按下
						cnt[j]++;
						a[j] = 1; // 標記當前按下
					}
				} else {
					a[j] = 0; //標記當前沒被按下
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (i != 10) cout << cnt[i] << " ";
			else cout << cnt[i];
		}
		cout << endl;
	}
}


// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;

int mp[256][11];

int main() {
    ios::sync_with_stdio(0);
    int tmp[][11] = {
        {0,0,1,1,1,0,0,1,1,1,1},
        {0,0,1,1,1,0,0,1,1,1,0},
        {0,0,1,1,1,0,0,1,1,0,0},
        {0,0,1,1,1,0,0,1,0,0,0},
        {0,0,1,1,1,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,1,1,1,1,0,0,1,1,1,0},
        {0,1,1,1,1,0,0,1,1,0,0},
        {0,1,1,1,1,0,0,1,0,0,0},
        {0,1,1,1,1,0,0,0,0,0,0},
        {0,1,1,1,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0,0}
    };

    string notes = "cdefgabCDEFGAB";
    for (int i = 0; i < notes.size(); i++)
        for (int j = 0; j <= 10; j++)
            mp[notes[i]][j] = tmp[i][j];

    string s;
    int t;
    cin >> t;
    
	getline(cin, s); //clear buffer
    while (t--) {
        getline(cin, s);
        int cnt[11] = {0};
        int a[11] = {0};
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j <= 10; j++) {
                if (mp[s[i]][j]) {
                    if (!a[j]) { // GPT 改善過的邏輯較簡單
                        a[j] = 1;
                        cnt[j]++;
                    }
                } else {
                    a[j] = 0;
                }
            }
        }
        for (int i = 1; i <= 10; i++) {
			if (i < 10) cout << cnt[i] << " ";
			else cout << cnt[i];
        }
        cout << "\n";
    }
}





// mp 初始化 g++4.6.3 不支援
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	map<char, vector<int> > mp;
	//         0  1  2  3  4  5  6  7  8  9  10
	mp['c'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
	mp['d'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	mp['e'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	mp['f'] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	mp['g'] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	mp['a'] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['b'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	mp['C'] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['D'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	mp['E'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	mp['F'] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	mp['G'] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	mp['A'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	mp['B'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	
	string s;
	int t;
	cin >> t;
	getline(cin, s); //clear buffer
	while (t--) {
		getline(cin, s);
		int cnt[11] = {0};
		int a[11] = {0}; // status
		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; j <= 10; j++) {
				if (mp[s[i]][j]) { // 查詢該音調的表
					if (a[j]) { // 若按住
						continue;
					} else {
						a[j] = 1; // 標記按住的狀態
						cnt[j]++; 
					}
				} else {
					a[j] = 0; // 切換為沒按住
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			if (i < 10) cout << cnt[i] << " ";
			else cout << cnt[i];
		}
		cout << "\n";
	}
}



