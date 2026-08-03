// g++4.6.3 AC
#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
    ios::sync_with_stdio(0);
    int n, m;
    char ch;
    int cnt=1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        // 讀取
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ch;
                if (ch == '*') a[i][j] = -1;
            }
        }
        // check
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != -1) {
                    // 左上
                    if (i-1 >= 0 && j-1 >= 0) // 沒出界才往下判斷
                        if (a[i-1][j-1] == -1)
                            a[i][j]++;
                    // 上
                    if (i-1 >= 0)
                        if (a[i-1][j] == -1)
                            a[i][j]++;
                    // 右上
                    if (i-1 >= 0 && j+1 <= m)
                        if (a[i-1][j+1] == -1)
                            a[i][j]++;
                    // 左 OK
                    if (j-1 >= 0)
                        if (a[i][j-1] == -1)
                            a[i][j]++;
                    // 右
                    if (j+1 <= m)
                        if (a[i][j+1] == -1)
                            a[i][j]++;
                    // 左下
                    if (i+1 <= n && j-1 >= 0)
                        if (a[i+1][j-1] == -1)
                            a[i][j]++;
                    // 下
                    if (i+1 <= n)
                        if (a[i+1][j] == -1)
                            a[i][j]++;
                    // 右下
                    if (i+1 <= n && j+1 <= m)
                        if (a[i+1][j+1] == -1)
                            a[i][j]++;
                }
            }
        }
        if (cnt !=1)
            cout << "\n";
        cout << "Field #" << cnt++ << ":" << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == -1)
                    cout << "*";
                else
                    cout << a[i][j];
                a[i][j] = 0; // 用完就清除
            }
            cout << "\n";
        }
    }
}

/*#include <bits/stdc++.h>*/
/*using namespace std;*/
/*int a[10000];*/
/*int main() {*/
/*    int n, m;*/
/*    char ch;*/
/*    int cnt = 1;*/
/*    while (cin >> n >> m) {*/
/*        if (n == 0 && m == 0) break;*/
/*        // 讀取*/
/*        for (int i = 0; i < n; i++) {*/
/*            for (int j = 0; j < m; j++) {*/
/*                cin >> ch;*/
/*                if (ch == '*') a[i * m + j] = -1; // 每個 row 有 m 個 */
/*            }*/
/*        }*/
/*        // 檢查*/
/*        for (int i = 0; i < n; i++) {*/
/*            for (int j = 0; j < m; j++) {*/
/*                int curr = i * m + j;*/
/*                // 反面寫法：使周圍八個格子+1*/
/*                if (a[curr] != -1) {*/
/*                    if (curr - 1 >= 0 && a[curr-1] == -1)*/
/*                            a[curr]++;*/
/*                    if (curr + 1 < n*m && a[curr+1] == -1)*/
/*                            a[curr]++;*/
/*                    if (curr + m < n*m && a[curr+m] == -1)*/
/*                            a[curr]++;*/
/*                    if (curr - m >= 0 && a[curr-m] == -1)*/
/*                            a[curr]++;*/
/*                    if (curr - m - 1 >= 0 && a[curr-m-1] == -1)*/
/*                            a[curr]++;*/
/*                    if (curr - m + 1 >= 0 && a[curr-m+1] == -1)*/
/*                            a[curr]++;*/
/*                    if (curr + m - 1 < n*m && a[curr+m-1] == -1)*/
/*                            a[curr]++;*/
/*                    if (curr + m + 1 < n*m && a[curr+m+1] == -1)*/
/*                            a[curr]++;*/
/*                }*/
/*            }*/
/*        }*/
/*        if (cnt !=1) cout << "\n";*/
/*        cout << "Field #" << cnt++ << ":" << "\n";*/
/*        for (int i = 0; i < n; i++) {*/
/*            for (int j = 0; j < m; j++) {*/
/*                int curr = i * m + j;*/
/*                if (a[curr] == -1)*/
/*                    cout << "*";*/
/*                else*/
/*                    cout << a[curr];*/
/*                a[curr] = 0; // 用完就清除*/
/*            }*/
/*            cout << "\n";*/
/*        }*/
/*    }*/
/*}*/


/*

4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0

0123
4567


4 4
*...
....
.*..
....
0 0

Field #1:
*100
2210
1*10
1110

4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0


-1 0 0 0
0 0 0 0
0 -1 0 0
0 0 0 0

-1 -1 0 0 0
0 0 0 0 0
0 -1 0 0 0


*/



#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
    ios::sync_with_stdio(0);
}