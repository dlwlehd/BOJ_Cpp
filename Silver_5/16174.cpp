#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

int n;
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int board[66][66];
bool vis[66][66] = {0};

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == n - 1) {
            cout << "HaruHaru";
            return 0;
        }
        for (int dir = 0; dir < 2; dir++) {
            int nx = x + board[x][y] * dx[dir];
            int ny = y + board[x][y] * dy[dir];
            if (oob(nx, ny) || vis[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    cout << "Hing";
}