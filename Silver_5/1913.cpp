#include <bits/stdc++.h>
using namespace std;

int n, target;
int board[1000][1000];
pair<int,int> p;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main(void) {
    input();
    cin >> n >> target;

    int rotate = n / 2;
    int idx = 1;
    board[n / 2][n / 2] = idx;

    int startX = n / 2 - 1;
    int startY = n / 2 - 1;

    for (int i = 1; i <= rotate; i++) {
        int x = startX;
        int y = startY;

        for (int dir = 0; dir < 4;) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if ((n / 2 - i <= nx && nx <= n / 2 + i) && (n / 2 - i <= ny && ny <= n / 2 + i)) {
                idx++;
                board[nx][ny] = idx;
                x = nx;
                y = ny;
            }
            else {
                dir++;
            }
        }
        startX--; startY--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
            if (board[i][j] == target) {
                p.first = i + 1;
                p.second = j + 1;
            }
        }
        cout << "\n";
    }
    cout << p.first << " " << p.second;
}