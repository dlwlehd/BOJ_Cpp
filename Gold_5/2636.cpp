#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;

int n, m, area, t = 0;
int board[102][102];
bool vis[102][102], air[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int calc() {
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j] || vis[i][j]) continue;
            queue<pi> q;
            q.push({i, j});
            vis[i][j] = 1;
            cnt++;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (oob(nx, ny) || !board[nx][ny] || vis[nx][ny]) continue;
                    cnt++;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return cnt;
}

void melt() {
    int temp_board[102][102];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) continue;
            bool c = false;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (oob(nx, ny)) continue;
                if (air[nx][ny]) {
                    c = true;
                    break;
                }
            }
            if (c)
                temp_board[i][j] = 0;
            else
                temp_board[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}

void air_check() {
    memset(air, 0, sizeof(air));
    queue<pi> q;
    q.push({0, 0});
    air[0][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (oob(nx, ny) || board[nx][ny] || air[nx][ny]) continue;
            air[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

bool empty_check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) return false;
        }
    }
    return true;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (!empty_check()) {
        t++;
        area = calc();
        air_check();
        melt();
    }

    cout << t << "\n"
         << area;
}