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
int board[52][52];
bool vis[52][52];
int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<pi> cloud;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool oob(int x, int y) { return x < 1 || x > n || y < 1 || y > n; }

void cloudMove(int d, int s) {
    for (int i = 0; i < cloud.size(); i++) {
        auto [x, y] = cloud[i];
        int nx = x + s * dx[d];
        int ny = y + s * dy[d];
        while (nx > n) nx -= n;
        while (ny > n) ny -= n;
        while (nx < 1) nx += n;
        while (ny < 1) ny += n;
        cloud[i] = {nx, ny};
    }
}

void rain() {
    for (auto [x, y] : cloud) {
        board[x][y]++;
        vis[x][y] = 1;
    }
}

void waterCopy() {
    for (auto [x, y] : cloud) {
        int cnt = 0;
        for (int dir = 0; dir < 8; dir += 2) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (oob(nx, ny)) continue;
            if (board[nx][ny]) cnt++;
        }
        board[x][y] += cnt;
    }
}

void cloudCreate() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j]) continue;

            if (board[i][j] >= 2) {
                cloud.push_back({i, j});
                board[i][j] -= 2;
            }
        }
    }
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = n - 1; i <= n; i++) {
        for (int j = 1; j <= 2; j++) {
            cloud.push_back({i, j});
        }
    }

    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        memset(vis, 0, sizeof(vis));
        if (d == 8) d = 0;
        cloudMove(d, s);
        rain();
        waterCopy();
        cloud.clear();
        cloudCreate();
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += board[i][j];
        }
    }
    cout << sum;
}