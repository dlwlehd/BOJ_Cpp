#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

int n, m, indegree[32002];
vector<int> adj[32002], res;
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    for (int i = 1; i <= n; i++) if (indegree[i] == 0) pq.push(i);
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        res.push_back(cur);
        for (int next: adj[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) pq.push(next);
        }
    }
    for (int i: res) cout << i << " ";
}