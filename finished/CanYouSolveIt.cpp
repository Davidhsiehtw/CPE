#include <bits/stdc++.h>
using namespace std;
int id(int x, int y) {
    int k = x + y;
    return k * (k + 1) / 2 + x;
}
int main() {
    int Case, index1, index2;
    int x1, y1, x2, y2;
    cin >> Case;
    for (int i = 1; i <= Case; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == 0 && y1 == 0) {
            index1 = 0;
            index2 = id(x2, y2);
        }
        else {
            index1 = id(x1, y1);
            index2 = id(x2, y2);
        }
        
        cout << "Case " << i << ": " << index2 - index1 << "\n";
    }
}

/*
 
3
0 0 0 1
0 0 1 0
0 0 0 2

*/

/*
// TLE
#include <bits/stdc++.h>
using namespace std;
int main() {
    int Case, cnt;
    int x1, y1, x2, y2;
    cin >> Case;
    for (int i = 1; i <= Case; i++) {
       while (cin >> x1 >> y1 >> x2 >> y2) {
           cnt = 0;
           while (x1 != x2 || y1 != y2) {
               if (x1 == 0 && y1 == 0) {
                   y1++;
               } else if (x1 == 0 || (x1 != 0 && y1 != 0)) {
                   x1++;
                   y1--;
               } else if (y1 == 0) {
                   y1 = x1 + 1;
                   x1 = 0;
               }
               cnt++; 
           }
            cout << "Case " << Case << ": " << cnt << "\n";
       }
    }
}
*/


