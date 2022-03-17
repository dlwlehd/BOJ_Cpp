#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<int> a[100002];
vector<int> dfs_order;
int parent[100002];
queue<int> q;
bool vis[100002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

void dfs(int x) {
    if (vis[x]) return;
    dfs_order.push_back(x);
    vis[x] = true;
    for (int y : a[x]) {
        dfs(y);
    }
}

int main() {
    input();

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u -= 1; v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> b(n);
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] -= 1;
        order[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end(), [&](const int& u, const int& v) {
            return order[u] < order[v];
            });
    }

    dfs(0);
    if (dfs_order == b) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}