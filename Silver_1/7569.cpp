#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define X first.second
#define Y second
#define Z first.first

int board[102][102][102];
int dist[102][102][102];
int dx[6] = { 0,0 ,1,-1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };
int dz[6] = { 0,0,0 ,0,-1,1 };
bool vis[102][102][102];
int n, m, h;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	queue<pair<pair<int,int>,int>> Q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];

				if (board[i][j][k] == 1) Q.push({{ i,j }, k});
				if (board[i][j][k] == 0) {
					dist[i][j][k] = -1;
				}
			}
		}
	}

	while (!Q.empty()) {
		pair<pair<int, int>, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int nz = cur.Z + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nz][nx][ny] >= 0) continue;
			dist[nz][nx][ny] = dist[cur.Z][cur.X][cur.Y] + 1;
			Q.push({ {nz,nx},ny });
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
}