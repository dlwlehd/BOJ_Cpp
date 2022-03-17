#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

int n, m;
int board[502][502];
int dp[502][502];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int sol(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    int& ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (oob(nx, ny) || board[nx][ny] >= board[x][y]) continue;
        ret += sol(nx, ny);
    }
    return ret;
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
    memset(dp, -1, sizeof(dp));
    cout << sol(0, 0);
}