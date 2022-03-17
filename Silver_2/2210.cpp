#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

char board[5][5];
set<string> s;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool oob(int x, int y) {
    return x < 0 || x >= 5 || y < 0 || y >= 5;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void dfs(int x, int y, string r, int cnt) {
    if (cnt == 5) {
        s.insert(r);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (oob(nx, ny)) continue;
        dfs(nx, ny, r + board[nx][ny], cnt + 1);
    }
}

int main() {
    input();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            string x = to_string(board[i][j]);
            dfs(i, j, x, 0);
        }
    }
    cout << s.size();
}