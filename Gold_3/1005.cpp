#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

int n, m, T, w, indegree[1002], t[1002], res[1002];
vector<int> adj[1002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        fill(indegree, indegree + n + 1, 0);
        fill(res, res + n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> t[i];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            indegree[v]++;
        }
        cin >> w;
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                res[i] = t[i];
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int next: adj[cur]) {
                res[next] = max(res[next], res[cur] + t[next]);
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
        cout << res[w] << '\n';
    }
}