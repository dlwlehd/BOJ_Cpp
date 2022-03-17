#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, n, m;
int board[51][51];
int vis[51][51];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

bool oob(int x, int y) {
    return x < 0 || x >= m || y < 0 || y >= n;
}

void bfs(int x, int y, int cnt) {
    queue<pair<int, int>> q;

    q.push({x, y});
    vis[x][y] = cnt;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (oob(nx, ny)) continue;
            if (vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
            q.push({nx, ny});
            vis[nx][ny] = cnt;
        }
    }
}

int main() {
    input();
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                vis[i][j] = 0;
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1 && vis[i][j] == 0) {
                    bfs(i, j, ++cnt);
                }
            }
        }

        cout << cnt << "\n";
    }
}