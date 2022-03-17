#include <bits/stdc++.h>

using namespace std;

int board[102][102] = {0};
bool vis[102][102] = {0};
int res = 0, n, m, k, s = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

bool oob(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    s++;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (oob(nx, ny) || !board[nx][ny] || vis[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {
    input();
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] && !vis[i][j]) {
                s = 0;
                dfs(i, j);
                res = max(s, res);
            }
        }
    }

    cout << res;
}