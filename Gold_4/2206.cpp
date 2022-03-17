#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define X first
#define Y second

string input[1002];
char board[1002][1002][2];
bool vis[1002][1002][2];
int dist[1002][1002][2];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 2; k++) {
				board[i][j][k] = '0';
				dist[i][j][k] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			board[i][j][0] = input[i][j - 1];
			board[i][j][1] = input[i][j - 1];
		}
	}

	queue<tuple<int, int, int>> Q;
	Q.push({ 1,1,0 });
	dist[1][1][0] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int curX, curY, curWall;
		tie(curX, curY, curWall) = cur;

		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int wall = curWall;

			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (dist[nx][ny][wall] > 0) continue;

			if (board[nx][ny][wall] == '1' && wall == 0) {
				Q.push({ nx,ny,1 });
				dist[nx][ny][1] = dist[curX][curY][curWall] + 1;
				continue;
			}
			else if (board[nx][ny][wall] == '1' && wall == 1) continue;

			else if (board[nx][ny][wall] == '0') {
				Q.push({ nx,ny,wall });
				dist[nx][ny][wall] = dist[curX][curY][curWall] + 1;
			}
		}
	}
	int result;
	if (dist[n][m][0] != 0 && dist[n][m][1] != 0) result = min(dist[n][m][0], dist[n][m][1]);
	else if (dist[n][m][0] == 0 && dist[n][m][1] == 0) result = -1;
	else result = max(dist[n][m][0], dist[n][m][1]);

	cout << result;
}
