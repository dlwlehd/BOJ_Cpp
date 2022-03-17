#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define X first
#define Y second

char board[1002][1002];
int dist_Ji[1002][1002];
int dist_Fire[1002][1002];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q_Ji;
queue<pair<int, int>> Q_Fire;

void bfs_fire() {
	while (!Q_Fire.empty()) {
		auto cur = Q_Fire.front();
		Q_Fire.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist_Fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			dist_Fire[nx][ny] = dist_Fire[cur.X][cur.Y] + 1;
			Q_Fire.push({ nx,ny });
		}
	}
}

void bfs_Ji() {
	while (!Q_Ji.empty()) {
		auto cur = Q_Ji.front();
		Q_Ji.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << dist_Ji[cur.X][cur.Y] + 1 << "\n";
				return;
			}
			if (dist_Ji[nx][ny] >= 0 || board[nx][ny] != '.') continue;
			if (dist_Fire[nx][ny] != -1 && dist_Fire[nx][ny] <= dist_Ji[cur.X][cur.Y] + 1) continue;
			dist_Ji[nx][ny] = dist_Ji[cur.X][cur.Y] + 1;
			Q_Ji.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {

		cin >> m >> n;

		for (int i = 0; i < n; i++) {
			fill(dist_Ji[i], dist_Ji[i] + m, -1);
			fill(dist_Fire[i], dist_Fire[i] + m, -1);
			fill(board[i], board[i] + m, 0);
		}
		Q_Ji = queue<pair<int, int>>();
		Q_Fire = queue<pair<int, int>>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				cin >> board[i][j];
				char x = board[i][j];

				if (x == '*') {
					Q_Fire.push({ i,j });
					dist_Fire[i][j] = 0;
				}
				if (x == '@') {
					Q_Ji.push({ i,j });
					dist_Ji[i][j] = 0;
				}
			}
		}

		bfs_fire();
		bfs_Ji();
	}
	return 0;
}
