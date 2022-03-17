#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[6][6];
bool vis[6][6];
int res = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void func(int x, int y, int sum) {
    if (y == m) {
        y = 0;
        x++;
    }
    if (x == n) {
        res = max(res, sum);
        return;
    }
    if (!vis[x][y]) {
        if (x + 1 < n && y - 1 >= 0 && !vis[x + 1][y] && !vis[x][y - 1]) {
            vis[x + 1][y] = true;
            vis[x][y - 1] = true;
            vis[x][y] = true;
            int tmp = sum + (board[x + 1][y] + (board[x][y] * 2) + board[x][y - 1]);
            func(x, y + 1, tmp);
            vis[x + 1][y] = false;
            vis[x][y - 1] = false;
            vis[x][y] = false;
        }
        if (x - 1 >= 0 && y - 1 >= 0 && !vis[x - 1][y] && !vis[x][y - 1]) {
            vis[x - 1][y] = true;
            vis[x][y - 1] = true;
            vis[x][y] = true;
            int tmp = sum + (board[x - 1][y] + (board[x][y] * 2) + board[x][y - 1]);
            func(x, y + 1, tmp);
            vis[x - 1][y] = false;
            vis[x][y - 1] = false;
            vis[x][y] = false;
        }
        if (x - 1 >= 0 && y + 1 < m && !vis[x - 1][y] && !vis[x][y + 1]) {
            vis[x - 1][y] = true;
            vis[x][y + 1] = true;
            vis[x][y] = true;
            int tmp = sum + (board[x - 1][y] + (board[x][y] * 2) + board[x][y + 1]);
            func(x, y + 1, tmp);
            vis[x - 1][y] = false;
            vis[x][y + 1] = false;
            vis[x][y] = false;
        }
        if (x + 1 < n && y + 1 < m && !vis[x + 1][y] && !vis[x][y + 1]) {
            vis[x + 1][y] = true;
            vis[x][y + 1] = true;
            vis[x][y] = true;
            int tmp = sum + (board[x + 1][y] + (board[x][y] * 2) + board[x][y + 1]);
            func(x, y + 1, tmp);
            vis[x + 1][y] = false;
            vis[x][y + 1] = false;
            vis[x][y] = false;
        }
    }
    func(x, y + 1, sum);
}

int main(void) {
    input();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            vis[i][j] = 0;
        }
    }

    func(0, 0, 0);
    cout << res;
}