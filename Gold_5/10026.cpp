#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

string board[102];
bool vis[102][102];
bool xvis[102][102];

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (board[i][j] != 'R' || vis[i][j]) continue;

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
					if (vis[nx][ny] || board[nx][ny] != 'R') continue;
					Q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (board[i][j] != 'G' || vis[i][j]) continue;

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
					if (vis[nx][ny] || board[nx][ny] != 'G') continue;
					Q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (board[i][j] != 'B' || vis[i][j]) continue;

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
					if (vis[nx][ny] || board[nx][ny] != 'B') continue;
					Q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
		}
	}

	int xcnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (board[i][j] != 'R' || xvis[i][j]) continue;

			queue<pair<int, int>> Q;
			xcnt++;
			Q.push({ i,j });
			xvis[i][j] = 1;

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (xvis[nx][ny] || board[nx][ny] != 'R') continue;
					Q.push({ nx,ny });
					xvis[nx][ny] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (board[i][j] != 'B' || xvis[i][j]) continue;

			queue<pair<int, int>> Q;
			xcnt++;
			Q.push({ i,j });
			xvis[i][j] = 1;

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (xvis[nx][ny] || board[nx][ny] != 'B') continue;
					Q.push({ nx,ny });
					xvis[nx][ny] = 1;
				}
			}
		}
	}

	cout << cnt << " " << xcnt;
}