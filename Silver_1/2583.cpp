#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int board[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[102][102];
int n, m, k;
int result[102];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		fill(board[i], board[i] + m, 1);
	}

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				board[j][k] = 0;
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;

			cnt++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 0;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				area++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			result[cnt - 1] = area;
		}
	}

	cout << cnt << "\n";
	
	sort(result, result + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << result[i] << " ";
	}
}
