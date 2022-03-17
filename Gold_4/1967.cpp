#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> p;

const int INF = 987654321;
int n, m, s, e;
vector<p> adj[10002];
int dist[10002];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	priority_queue<p, vector<p>, greater<p>> pq;
	fill(dist + 1, dist + n + 1, INF);
	pq.push({0, 1});
	dist[1] = 0;
	while (!pq.empty()) {
		auto [cost, cur] = pq.top(); pq.pop();
		if (dist[cur] != cost) continue;
		
		for (auto [next, d] : adj[cur]) {
			if (dist[next] > cost + d) {
				dist[next] = cost + d;
				pq.push({dist[next], next});
			}
		}
	}
	
	int d = 0, idx = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[i] > d) {
			idx = i;
			d = dist[i];
		}
	}
	
	fill(dist, dist + n + 1, INF);
	pq.push({0, idx});
	dist[idx] = 0;
	while (!pq.empty()) {
		auto [cost, cur] = pq.top(); pq.pop();
		if (dist[cur] != cost) continue;
		
		for (auto [next, d] : adj[cur]) {
			if (dist[next] > cost + d) {
				dist[next] = cost + d;
				pq.push({dist[next], next});
			}
		}
	}
	
	cout << *max_element(dist + 1, dist + n + 1);
}