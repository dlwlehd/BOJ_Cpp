#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[102][102];
int d[102][102];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
deque<pair<int, int>> q;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main() {
    input();

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
            d[i][j] = -1;
        }
    }
    q.push_back({ 0,0 });
    d[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (d[nx][ny] == -1) {
                if (board[nx][ny] == 0) {
                    d[nx][ny] = d[x][y];
                    q.push_front({ nx,ny });
                }
                else {
                    d[nx][ny] = d[x][y] + 1;
                    q.push_back({ nx,ny });
                }
            }
        }
    }

    cout << d[n - 1][m - 1];
}