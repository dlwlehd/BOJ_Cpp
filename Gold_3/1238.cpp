#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> p;

int n, m, x;
const int INF = 987654321;
vector<p> adj[1002], adj1[1002];
int dist[1002], dist1[1002];
bool vis[1002];
int res = -1;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

void dij(int *dist, vector<p> *adj) {
	priority_queue<p, vector<p>, greater<p>> pq;
	dist[x] = 0;
	pq.push({0, x});
	
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && vis[cur]);
		if (vis[cur]) break;
		
		vis[cur] = 1;
		for (auto& t: adj[cur]) {
			int next = t.first;
			int d = t.second;
			
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push({dist[next], next});
			}
		}
	}
}

int main() {
    input();
	
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj1[v].push_back({u, w});
	}
	
	fill(dist, dist + n + 1, INF);
	fill(dist1, dist1 + n + 1, INF);
	fill(vis, vis + n + 1, 0);
	dij(dist, adj);
	fill(vis, vis + n + 1, 0);
	dij(dist1, adj1);
	
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		res = max(res, dist[i] + dist1[i]);
	}
	
	cout << res;
}