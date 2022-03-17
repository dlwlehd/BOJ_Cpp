#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m;
string board[1500];
queue<pi> water, swan;
set<pi> water_n, swan_n;
bool vis[1500][1500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 'X') water.push({i, j});
            if (board[i][j] == 'L' && swan.empty()) {
                swan.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int res = 0;
    while (1) {
        bool find = false;
        while (!swan.empty() && !find) {
            auto [x, y] = swan.front();
            swan.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny])
                    continue;
                if (board[nx][ny] == 'X')
                    swan_n.insert({nx, ny});
                else if (board[nx][ny] == 'L') {
                    find = true;
                    break;
                } else {
                    swan.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        if (find) break;
        for (auto it = swan_n.begin(); it != swan_n.end(); it++) swan.push(*it);
        swan_n.clear();
        res++;
        while (!water.empty()) {
            auto [x, y] = water.front();
            water.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == 'X') water_n.insert({nx, ny});
            }
        }
        for (auto it = water_n.begin(); it != water_n.end(); it++) {
            auto [x, y] = *it;
            board[x][y] = '.';
            water.push({x, y});
        }
        water_n.clear();
    }
    cout << res << '\n';
}