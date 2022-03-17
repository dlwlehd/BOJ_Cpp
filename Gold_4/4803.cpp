#include <bits/stdc++.h>

using namespace std;

bool vis[502] = {0};
vector<int> adj[502];
set<int> a;

int line, node;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void dfs(int cur) {
    vis[cur] = 1;
    node++;
    for (int next: adj[cur]) {
        line++;
        if (!vis[next]) {
            dfs(next);
        }
    }
}

int main() {
    input();
    int n, m;
    int t = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) adj[i].clear();
        fill(vis, vis + 502, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int idx = 0;
        for (int i = 1; i <= n; i++) {
            line = 0;
            node = 0;
            if (!vis[i]) {
                dfs(i);
            } else continue;
            if (line / 2 == node - 1) idx++;
        }

        cout << "Case " << t << ": ";
        if (idx == 0) cout << "No trees.\n";
        else if (idx == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << idx << " trees.\n";
        t++;
    }
}