#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define X first
#define Y second

int n, m;
int board[302][302];
int temp[302][302];
bool vis[302][302];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int melt(int x, int y) {
	int z_cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int tx = x + dx[dir];
		int ty = y + dy[dir];

		if (board[tx][ty] == 0)
			z_cnt++;
	}
	return z_cnt;
}

void bfs(int a, int b) {

	queue<pair<int, int>> Q;
	Q.push({ a,b });
	vis[a][b] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 1 || nx >= n || ny < 1 || ny >= m) continue;
			if (board[nx][ny] == 0 || vis[nx][ny]) continue;

			Q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	int year = 0;

	while (true) {

		for (int i = 1; i <= n; i++) {
			fill(temp[i] + 1, temp[i] + 1 + m, 0);
			fill(vis[i] + 1, vis[i] + 1 + m, 0);
		}

		int cnt = 0;

		for (int i = 1; i <= n - 1; i++) {
			for (int j = 1; j <= m - 1; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;

				cnt++;
				bfs(i, j);
			}
		}

		if (cnt > 1) {
			cout << year;
			break;
		}

		else if (cnt == 0) {
			cout << 0;
			break;
		}

		year++;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] != 0)
				{
					temp[i][j] = board[i][j] - melt(i, j);
					if (temp[i][j] < 0) temp[i][j] = 0;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				board[i][j] = temp[i][j];
			}
		}
	}
}
