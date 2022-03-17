#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
typedef pair<int, int> pi;

int n;
int board[502][502];
int dp[502][502];
int res = -1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pi> q;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int dfs(int x, int y) {
    if (dp[x][y] != 1) return dp[x][y];
    dp[x][y] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (oob(nx, ny) || board[x][y] >= board[nx][ny]) continue;
        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) fill(dp[i], dp[i] + n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dfs(i, j));
        }
    }
    cout << res;
}