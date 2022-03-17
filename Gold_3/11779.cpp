#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> p;

const int INF = 987654321;
int n, m, s, e;
vector<p> adj[1002];
int dist[1002];
int prv[1002];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	cin >> s >> e;
	
	priority_queue<p, vector<p>, greater<p>> pq;
	fill(dist, dist + n + 1, INF);
	pq.push({0, s});
	dist[s] = 0;
	while (!pq.empty()) {
		auto [cost, cur] = pq.top(); pq.pop();
		if (dist[cur] != cost) continue;
		
		for (auto [next, d] : adj[cur]) {
			if (dist[next] > cost + d) {
				dist[next] = cost + d;
				prv[next] = cur;
				pq.push({dist[next], next});
			}
		}
	}
	
	vector<int> path;
	auto cur = e;
	while (cur != s) {
		path.push_back(cur);
		cur = prv[cur];
	}
	path.push_back(cur);
	reverse(path.begin(), path.end());
	cout << dist[e] << "\n" << path.size() << "\n";
	for (int i : path) cout << i << " ";

}