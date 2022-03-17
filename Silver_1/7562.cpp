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
int dist[102][102];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		fill(board[i], board[i] + n, 0);
	}
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, -1);
	}

	int cur_x, cur_y;
	int goal_x, goal_y;

	cin >> cur_y, cur_x, goal_y, goal_y;

	vis[cur_x][cur_y] = 1;
	queue<pair<int, int>> Q;
	Q.push({ cur_x,cur_y });
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
