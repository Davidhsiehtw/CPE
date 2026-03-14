#include <bits/stdc++.h>
using namespace std;
//          N  E  S  W
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int a[50][50]; // 座標從 0,0 ~ 50,50
int main() {
	int row, col, x, y, nextX, nextY;
	int D; // 方向索引值
	char dir;
	string move;
	bool lost = false;
	map<char, int> mp;
	map<int, char> mp2;
	mp['N'] = 0; mp2[0] = 'N';
	mp['E'] = 1; mp2[1] = 'E'; 
	mp['S'] = 2; mp2[2] = 'S';
	mp['W'] = 3; mp2[3] = 'W';
	cin >> row >> col;
	while (cin >> x >> y >> dir >> move) {
		D = mp[dir];
		lost = false;
		for (int i = 0; i < move.size(); i++) {
			if (move[i] == 'F') {
				// 根據 dir 決定 index of dx dy
				nextX = x + dx[D];
				nextY = y + dy[D];
				// 邊際判斷
				if (nextX >= 0 && nextX <= row &&
					nextY >= 0 && nextY <= col) {
					// 符合標準 則更新座標
					x = nextX;
					y = nextY;
				} else {
					if (a[x][y] == 1) {
						continue; // 已被標記過的話則 continue 繼續走
					} else {
						cout << x << " " << y << " " << mp2[D] << " LOST\n";
						lost = true;
						a[x][y] = 1;
						break; // NOTE: 掉出去後迴圈就得停了
					}
				}
			}
			else if (move[i] == 'R'){
				D = (D + 1) % 4;
			}
			else {
				D = (D - 1 + 4) % 4;
			}
		}
		if (!lost) cout << x << " " << y << " " << mp2[D] << "\n";
	}
}



// 第二次嘗試寫
#include <bits/stdc++.h>
using namespace std;
int a[50][50];
//          N  E  S  W
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
	int row, col, x, y, nX, nY;
	int D; // 方向索引直
	cin >> row >> col;
	char dir;
	string move;
	bool lost = false;
	map<char, int> mp;
	map<int, char> mp2;	
	mp['N'] = 0; mp2[0] = 'N';
	mp['E'] = 1; mp2[1] = 'E';
	mp['S'] = 2; mp2[2] = 'S';
	mp['W'] = 3; mp2[3] = 'W';
	while (cin >> x >> y >> dir >> move) {
		D = mp[dir]; // N=0 S=1 E=2 W=3
		for (int i = 0; i < move.size(); i++) {
			// move 是 'F' 'R' 'L' 其中之一 先決定方向
			lost = false;
			if (move[i] == 'F') {
				nX = x + dx[D];
				nY = y + dy[D];
				if (nX <= row && nY <= col && nX >= 0 && nY >= 0) {
					x = nX;
					y = nY;
				}
				else {
					// 出界
					if (a[x][y] == 1)
						continue;
					else {
						a[x][y] = 1; // 標記
						cout << x << " " << y << " " << mp2[D] << " LOST\n";
						lost = true;
						break;
					}
				}
			}
			else if (move[i] == 'L') {
				// W=3 -> S=2
				// S=2 -> E=1
				// E=1 -> N=0
				// N=0 -> W=3 ; -1 + 4
				D = (D-1 + 4) % 4;
			}
			else {
				// W=3 <- S=2
				// S=2 <- E=1
				// E=1 <- N=0
				// N=0 <- W=3 ; +1 
				D = (D+1) % 4;
			}
		}
		if (!lost)
			cout << x << " " << y << " " << mp2[D] << "\n";
	}
}