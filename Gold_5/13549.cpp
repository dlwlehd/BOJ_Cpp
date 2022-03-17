#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[100002];
int dist[100002];
int n, k;

void bfs() {

	fill(dist, dist+ 100001, -1);
	queue<int> Q;
	Q.push(n);
	dist[n] = 0;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		if (cur == k) {
			cout << dist[k];
			return;
		}

		for (int nxt : {2 * cur, cur - 1, cur + 1}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] >= 0) continue;

			if (nxt == 2 * cur) {
				dist[nxt] = dist[cur];
				Q.push(nxt);
			}
			else {
				dist[nxt] = dist[cur] + 1;
				Q.push(nxt);
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs();
}
