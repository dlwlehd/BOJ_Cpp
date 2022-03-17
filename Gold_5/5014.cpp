#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int dist[1000002];
bool vis[1000002];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	queue<int> Q;
	Q.push(s);

	fill(dist, dist + f, -1);

	dist[s] = 0;
	vis[s] = 1;

	int dy[2] = { u,-d };
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 2; dir++) {
			int ny = cur + dy[dir];

			if (ny < 1 || ny > f) continue;
			if (vis[ny]) continue;
			Q.push(ny);
			vis[ny] = 1;
			dist[ny] = dist[cur] + 1;
		}
	}

	if (s != g && dist[g] < 1) cout << "use the stairs" << "\n";
	else cout << dist[g] << "\n";

}
