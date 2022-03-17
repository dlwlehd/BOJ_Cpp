#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, n, m;
char board[51][51];
int dist[51][51];
bool vis[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool dfs(int x, int y, int cnt, char color) {
    if (vis[x][y]) {
        if (cnt - dist[x][y] >= 4)
            return true;
        else
            return false;
    }

    vis[x][y] = 1;
    dist[x][y] = cnt;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (oob(nx, ny))
            continue;
        if (board[nx][ny] != color)
            continue;

        if (dfs(nx, ny, cnt + 1, color))
            return true;
    }
    return false;
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            bool flag = dfs(i,j,1,board[i][j]);
            if (flag) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}