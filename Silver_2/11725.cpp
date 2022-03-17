#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100002];
int parent[100002];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void dfs(int cur) {
    for (int next: adj[cur]) {
        if (parent[next] == -1) {
            parent[next] = cur;
            dfs(next);
        }
    }
}

int main() {
    input();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(parent, parent + n, -1);
    dfs(0);
    for (int i = 1; i < n; i++) cout << parent[i] + 1 << "\n";
}