#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

int n, m, indegree[1002];
vector<int> adj[1002];

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
        int x, u, v;
        cin >> x >> u;
        for (int i = 0; i < x - 1; i++) {
            cin >> v;
            adj[u].push_back(v);
            indegree[v]++;
            u = v;
        }
    }
    vector<int> res;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto next: adj[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (sz(res) == n) for (int i: res) cout << i << '\n';
    else cout << 0;
}