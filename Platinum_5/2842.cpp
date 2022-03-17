#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;

int n, ans = 1e9;
char board[52][52];
int altitude[52][52];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
pi start;
vector<pi> home;
vector<int> w;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

bool bfs(int mn, int mx) {
    if (!(mn <= altitude[start.X][start.Y] && altitude[start.X][start.Y] <= mx)) return 0;
    
    bool vis[52][52];
    memset(vis, 0, sizeof(vis));
    queue<pi> q;
    q.push(start);
    vis[start.X][start.Y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (oob(nx, ny) || vis[nx][ny] || !(mn <= altitude[nx][ny] && altitude[nx][ny] <= mx)) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    
    for (auto [x, y]: home) {
		if (!vis[x][y]) return 0;
	}
    return 1;
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'P') {
                start.X = i;
                start.Y = j;
            }
            
            if (board[i][j] == 'K') {
                home.push_back({i, j});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> altitude[i][j];
            w.push_back(altitude[i][j]);
        }
    }
    
    sort(all(w));
    w.erase(unique(all(w)), w.end());
    
    for (int i = 0; i < w.size(); i++) {
		int lo = i - 1, hi = w.size() - 1;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			if (!bfs(w[i], w[mid])) lo = mid;
			else hi = mid;
		}
		if (bfs(w[i], w[hi])) {
			ans = min(ans, w[hi] - w[i]);
		}
	}
    cout << ans;

}