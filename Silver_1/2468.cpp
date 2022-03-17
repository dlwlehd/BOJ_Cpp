#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int board[102][102];

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int maxnum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] > maxnum) maxnum = board[i][j];
		}
	}

	int res = 0;

	for (int t = 0; t < maxnum; t++) {

		int sink[102][102];
		bool vis[102][102];

		for (int i = 0; i < n; i++) {
			fill(sink[i], sink[i] + n, 0);
			fill(vis[i], vis[i] + n, 0);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > t) sink[i][j] = 1;
			}
		}
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (sink[i][j] == 0 || vis[i][j]) continue;

				queue<pair<int, int>> Q;
				cnt++;
				Q.push({ i,j });
				vis[i][j] = 1;

				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || sink[nx][ny] == 0) continue;
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		res = max(cnt, res);
	}
	cout << res;
}