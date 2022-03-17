#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int k, n, m;
int board[202][202];
bool vis[202][202][32];

int hx[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int hy[8] = { 1, -1, 1, -1, 2, 2, -2, -2 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<tuple<int, int, int, int>> Q;

int bfs() {
	Q.push({ 0,0,0,0 });
	vis[0][0][0] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int curX, curY, horse, cnt;
		tie(curX, curY, horse, cnt) = cur;

		if (curX == n - 1 && curY == m - 1) {
			return cnt;
		}

		if (horse < k) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = curX + hx[dir];
				int ny = curY + hy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == 1 || vis[nx][ny][horse + 1]) continue;

				vis[nx][ny][horse + 1] = 1;
				Q.push({ nx,ny,horse + 1,cnt + 1 });
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 1 || vis[nx][ny][horse]) continue;

			vis[nx][ny][horse] = 1;
			Q.push({ nx,ny,horse,cnt + 1 });
		}
	}
	return -1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int result = bfs();

	cout << result;
}