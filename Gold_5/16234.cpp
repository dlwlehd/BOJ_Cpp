#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, l, r, cnt = 0;
int board[52][52];
bool vis[52][52], opened[52][52];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool oob(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool isEndSame() {
    int x = board[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != x) return false;
        }
    }
    return true;
}

bool isEndOpen() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (opened[i][j]) return true;
        }
    }
    return false;
}

void borderOpen() {
    memset(opened, 0, sizeof(opened));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int diff = abs(board[i][j] - board[i][j + 1]);
            if (diff >= l && diff <= r) opened[i][j] = opened[i][j + 1] = 1;
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            int diff = abs(board[i][j] - board[i + 1][j]);
            if (diff >= l && diff <= r) opened[i][j] = opened[i + 1][j] = 1;
        }
    }
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            int sum = board[i][j], boardCnt = 1;
            queue<pi> q;
            vector<pi> changed;
            changed.push_back({i, j});
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    int diff = abs(board[x][y] - board[nx][ny]);
                    if (oob(nx, ny) || vis[nx][ny]) continue;
                    if (!(diff >= l && diff <= r)) continue;
                    vis[nx][ny] = 1;
                    sum += board[nx][ny];
                    boardCnt++;
                    q.push({nx, ny});
                    changed.push_back({nx, ny});
                }
            }

            sum /= boardCnt;
            for (auto i : changed) board[i.X][i.Y] = sum;
        }
    }
}

int main() {
    input();
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {
        if (isEndSame()) break;

        borderOpen();
        if (!isEndOpen()) break;

        cnt++;
        bfs();
    }
    cout << cnt;
}