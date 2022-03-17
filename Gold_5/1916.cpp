#include <bits/stdc++.h>
using namespace std;

int n, m;
int u, v, w;
int s, e;
int dist[1002];
bool vis[1002] = {0};
int INF = 987654321;
typedef pair<int,int> P;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
	cin >> n >> m;
	vector<P> adj[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	cin >> s >> e;
	
	fill(dist, dist + n + 1, INF);
	dist[s] = 0;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({0, s});
	
	while(!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while(!pq.empty() && vis[curr]);
		
		if (vis[curr]) break;
		
		vis[curr] = 1;
		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push({dist[next], next});
			}
		}
	}
	
	cout << dist[e];
}