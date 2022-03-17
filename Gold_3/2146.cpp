#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define X first
#define Y second

int n;
int board[202][202];
bool vis[202][202];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<tuple<int, int, int>> Q;

void color() { // 다른 대륙 표시

	for (int k = 0; k < n; k++) {
		fill(vis[k], vis[k] + n, 0);
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (vis[i][j] || board[i][j] == 0) continue;

			cnt++;
			queue<pair<int, int>> q;

			q.push({ i,j });
			vis[i][j] = 1;
			board[i][j] = cnt;

			while (!q.empty()) {

				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;

					board[nx][ny] = cnt;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}
}


int bfs() {

	int res = 10000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;

			for (int k = 0; k < n; k++) {
				fill(vis[k], vis[k] + n, 0);
			}

			Q.push({ i,j,0 });
			vis[i][j] = 1;
			int clr = board[i][j];

			int x;
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				int curX, curY, dist;
				tie(curX, curY, dist) = cur;

				for (int dir = 0; dir < 4; dir++) {
					int nx = curX + dx[dir];
					int ny = curY + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 초과
					if (vis[nx][ny]) continue; // 방문했던 곳

					if (board[nx][ny] == clr) { // 같은 색 대륙
						vis[nx][ny] = 1;
						Q.push({ nx,ny,dist});
					}

					else if (board[nx][ny] == 0) { // 바다
						Q.push({ nx,ny,dist + 1 });
						vis[nx][ny] = 1;
					}

					else if (board[nx][ny] != clr) { // 처음 대륙 만날 때
						res = min(dist, res);
					}

				}
			}
		}
	}

	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	color();

	int result = bfs();
	cout << result;
}