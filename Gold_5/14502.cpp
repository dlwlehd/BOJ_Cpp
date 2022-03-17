#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
#define x first
#define y second

int n, m;
int mx = -1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[8][8];
bool vis[8][8];
vector<pi> blank;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs() {
    int board_t[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board_t[i][j] = board[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
    int area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board_t[i][j] == 2 && !vis[i][j]) {
                queue<pi> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto[curX, curY] = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curX + dx[dir];
                        int ny = curY + dy[dir];
                        if (oob(nx, ny) || vis[nx][ny] || board_t[nx][ny] == 1) continue;
                        q.push({nx, ny});
                        board_t[nx][ny] = 2;
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board_t[i][j] == 0) area++;
        }
    }

    mx = max(mx, area);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) blank.push_back({i, j});
        }
    }

    for (int i = 0; i < blank.size(); i++) {
        for (int j = i + 1; j < blank.size(); j++) {
            for (int k = j + 1; k < blank.size(); k++) {
                board[blank[i].x][blank[i].y] = 1;
                board[blank[j].x][blank[j].y] = 1;
                board[blank[k].x][blank[k].y] = 1;
                bfs();
                board[blank[i].x][blank[i].y] = 0;
                board[blank[j].x][blank[j].y] = 0;
                board[blank[k].x][blank[k].y] = 0;
            }
        }
    }
    cout << mx;
}