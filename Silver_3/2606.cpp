#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, cnt = 0;
vector<int> a[102];
queue<int> q;
bool vis[102];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : a[x]) {
            if (!vis[y]) {
                vis[y] = 1;
                q.push(y);
                cnt++;
            }
        }
    }
    cout << cnt;
}