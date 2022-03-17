#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> ti;

vector<ti> adj[130][130];
int n;
const int INF = 987654321;
int board[130][130];
int dist[130][130];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
	int t = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				adj[i][j].clear();
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					adj[i][j].push_back({board[nx][ny], nx, ny});
				}
			}
		}
		
		for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, INF);
		priority_queue<ti, vector<ti>, greater<ti>> pq;
		pq.push({board[0][0], 0, 0});
		dist[0][0] = board[0][0];
		
		while (!pq.empty()) {
			auto [cost, x, y] = pq.top(); pq.pop();
			if (dist[x][y] != cost) continue;
			
			for (auto [ncost, nx, ny]: adj[x][y]) {
				if (dist[nx][ny] > cost + ncost) {
					dist[nx][ny] = cost + ncost;
					pq.push({dist[nx][ny], nx, ny});
				}
			}
		}

		cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";
		t++;
	}
}