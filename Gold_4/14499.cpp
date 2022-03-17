#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int n, m, x, y, k;
int cmd[1002];
int dice[] = { 0,0,0,0,0,0 }; // 1,2,3,4,5,6
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

void rotate(int n) {
    int tdice[6];
    for (int i = 0; i < 6; i++) tdice[i] = dice[i];

    if (n == 1) {
        dice[0] = tdice[3];
        dice[2] = tdice[0];
        dice[3] = tdice[5];
        dice[5] = tdice[2];
    }

    else if (n == 2) {
        dice[0] = tdice[2];
        dice[2] = tdice[5];
        dice[3] = tdice[0];
        dice[5] = tdice[3];
    }

    else if (n == 3) {
        dice[0] = tdice[4];
        dice[1] = tdice[0];
        dice[4] = tdice[5];
        dice[5] = tdice[1];
    }

    else {
        dice[0] = tdice[1];
        dice[1] = tdice[5];
        dice[4] = tdice[0];
        dice[5] = tdice[4];
    }
}

int main(void) {
    input();
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < k; i++) {
        cin >> cmd[i];
    }

    for (int i = 0; i < k; i++) {
        int nx = x + dx[cmd[i] - 1];
        int ny = y + dy[cmd[i] - 1];
        if (oob(nx, ny)) continue;

        x = nx;
        y = ny;
        
        rotate(cmd[i]);
        if (board[x][y] == 0) board[x][y] = dice[5];
        else {
            dice[5] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[0] << "\n";
    }
}