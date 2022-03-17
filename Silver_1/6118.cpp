#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[20002];
int dist[20002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dist, dist + n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next: adj[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    int res = 0;
    int idx;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > res) {
            res = dist[i];
            idx = i;
        }
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == res) x++;
    }
    cout << idx << " " << res << " " << x;
}