#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, q;
vector<pi> adj[5002];
int dist[5002];
bool vis[5002];
const int INF = 1e9 + 7;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void dfs(int cur) {
    vis[cur] = 1;
    for (auto next : adj[cur]) {
        if (!vis[next.X]) {
            dist[next.X] = min(dist[cur], next.Y);
            dfs(next.X);
        }
    }
}

int main() {
    input();
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < q; i++) {
        int k, v, cnt = 0;
        cin >> k >> v;
        fill(dist, dist + n + 1, INF);
        fill(vis, vis + n + 1, 0);
        dfs(v);
        for (int i = 1; i <= n; i++) {
            if (i == v) continue;
            if (dist[i] >= k) cnt++;
        }
        cout << cnt << "\n";
    }
}