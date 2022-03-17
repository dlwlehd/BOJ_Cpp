#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

string board[32][32];
int dist[32][32][32];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		int l, r, c; // l : 층(z) r : 행(x) c : 열(y) board[z][x][y]
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> board[i][j];
			}
		}

		int startX, startY, startZ;
		int endX, endY, endZ;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					if (board[i][j][k] == 'S') {
						startX = j;
						startY = k;
						startZ = i;
					}
					else if (board[i][j][k] == 'E') {
						endX = j;
						endY = k;
						endZ = i;
					}
				}
			}
		}

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					char x = board[i][j][k];
					if (x == 'S' || x == '.' || x == 'E') {
						board[i][j][k] = '1';
					}
					else {
						board[i][j][k] = '0';
					}
				}
			}
		}

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					dist[i][j][k] = -1;
				}
			}
		}

		queue<tuple<int, int, int>> Q;
		Q.push({ startZ,startX,startY });
		dist[startZ][startX][startY] = 0;

		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			int curX, curY, curZ;
			tie(curZ, curX, curY) = cur;
			for (int dir = 0; dir < 6; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
				if (dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == '0') continue;

				Q.push({ nz,nx,ny });
				dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
			}
		}

		int result = dist[endZ][endX][endY];

		if (result == -1) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << result << " minute(s)." << "\n";
	}
}
