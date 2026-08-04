#include <bits/stdc++.h>
using namespace std;
//          N  E  S  W
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int a[50][50];
int main() {
    ios::sync_with_stdio(0); 
    int row, col, x, y, nX, nY;
    string move = "";
    char dir;
    bool lost = false;
    cin >> row >> col; // 5 3
    map<char, int> mp;
    map<int, char> mp2;
    mp['N'] = 0; mp2[0] = 'N';
    mp['E'] = 1; mp2[1] = 'E';
    mp['S'] = 2; mp2[2] = 'S';
    mp['W'] = 3; mp2[3] = 'W';
    while (cin >> x >> y >> dir >> move) {
        int d = mp[dir]; // init d
        for (int i = 0; i < move.size(); i++) { // RFRFRFRF
            lost = false;
            if (move[i] == 'F') {
                nX = x + dx[d];
                nY = y + dy[d];
                if (nX >= 0 && nX <= row && nY >= 0 && nY <= col) {
                    x = nX;
                    y = nY;
                } else {
                    if (a[x][y] == 1) {
                        continue;
                    } else {
                        cout << x << " " << y << " " << mp2[d] << " LOST\n";
                        lost = true;
                        a[x][y] = 1;
                        break;
                    }
                }

            } else if (move[i] == 'L') {
                // N=0 -> W=3
                // W=3 -> S=2
                // S=2 -> E=1
                // E=1 -> N=0
                d = (d - 1 + 4) % 4;
            } else {
                d = (d + 1) % 4;
            }
        }
        if (!lost)
            cout << x << " " << y << " " << mp2[d] << endl;
    }
}
