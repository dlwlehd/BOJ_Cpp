#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[51][51];
int n, m, k;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {

		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
		}
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + m, 0);
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
			board[x][y] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;

				cnt++;
				queue<pair<int, int>> Q;
				vis[i][j] = 1;
				Q.push({ i,j });

				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}

			}
		}
		cout << cnt << "\n";
	}
}