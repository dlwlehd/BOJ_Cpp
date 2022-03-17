#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

int n, indegree[10002], t[10002], dist[10002];
vector<int> adj[10002];


void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, v;
        cin >> t[i] >> x;
        for (int j = 0; j < x; j++) {
            cin >> v;
            adj[i].push_back(v);
            indegree[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dist[i] = t[i];
        }
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int next: adj[cur]) {
            dist[next] = max(dist[next], dist[cur] + t[next]);
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }
    
    cout << *max_element(dist + 1, dist + n + 1);
}