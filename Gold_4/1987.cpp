#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
typedef pair<int, int> pi;

int n, m;
char board[22][22];
bool check[26] = {0};
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
    return x < 0 || x >= n || y < 0 || y >= m;
}

void dfs(int x, int y, int idx) {
    res = max(res, idx);
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (oob(nx, ny) || check[board[nx][ny] - 'A']) continue;
        check[board[nx][ny] - 'A'] = 1;
        dfs(nx, ny, idx + 1);
        check[board[nx][ny] - 'A'] = 0;
    }
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    check[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << res;
}