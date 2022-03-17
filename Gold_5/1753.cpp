#include <bits/stdc++.h>
using namespace std;

int v, e, k;
int U, V, W;
int max_v = 20002;
int INF = 987654321;
typedef pair<int,int> P;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
	cin >> v >> e >> k;
	vector<P> adj[v];
	k--;
	for (int i = 0; i < e; i++) {
		cin >> U >> V >> W;
		adj[U - 1].push_back({V - 1, W});
	}
	
	int dist[max_v];
	fill(dist, dist + v, INF);
	bool vis[max_v] = {0};
	priority_queue<P, vector<P>, greater<P>> pq;
	dist[k] = 0;
	pq.push({0, k});
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
			if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                pq.push({dist[next], next});
            }
		}
	}
	
	   for(int i = 0; i < v; i++){
        if(dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}