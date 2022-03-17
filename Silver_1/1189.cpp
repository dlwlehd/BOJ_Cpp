#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m, d, res = 0;
char board[10][10];
bool vis[10][10] = {0};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool oob(int x, int y) { return x < 1 || x > n || y < 1 || y > m; }

void func(int x, int y, int dist) {
    if (x == 1 && y == m) {
        if (dist == d) res++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (oob(nx, ny) || vis[nx][ny] || board[nx][ny] == 'T') continue;
        vis[nx][ny] = 1;
        func(nx, ny, dist + 1);
        vis[nx][ny] = 0;
    }
}

int main() {
    input();
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    vis[n][1] = 1;
    func(n, 1, 1);
    cout << res;
}