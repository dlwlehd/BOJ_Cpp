#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
#define x first
#define y second

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[22][22];
int dist[22][22];
int s = 2, cnt = 0, ans = 0;
pi pos;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

bool cmp(pi a, pi b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) pos = {i, j};
        }
    }

    while (true) {
        for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);

        queue<pi> q;
        q.push(pos);
        dist[pos.x][pos.y] = 0;
        while (!q.empty()) {
            auto[curX, curY] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                if (oob(nx, ny) || board[nx][ny] > s || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[curX][curY] + 1;
                q.push({nx, ny});
            }
        }

        int eatable = 0;
        vector<pi> e;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 0 && board[i][j] != 9 && s > board[i][j] && dist[i][j] != -1) {
                    e.push_back({i, j});
                    eatable++;
                }
            }
        }
        if (eatable == 0) break;

        int t = 1e9;
        vector<pi> a;
        for (int i = 0; i < eatable; i++) {
            if (t > dist[e[i].x][e[i].y]) t = dist[e[i].x][e[i].y];
        }
        for (int i = 0; i < eatable; i++) {
            if (t == dist[e[i].x][e[i].y]) a.push_back(e[i]);
        }
        sort(a.begin(), a.end(), cmp);

        ans += dist[a[0].x][a[0].y];
        pi res = a[0];
        cnt++;
        if (cnt == s) {
            s++;
            cnt = 0;
        }
        board[pos.x][pos.y] = 0;
        pos = res;
        board[pos.x][pos.y] = 9;
    }
    
    cout << ans;
}