#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, u, v;
vector<int> a[3002];
int dist[3002];
int vis[3002];
queue<int> q;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int func(int x, int p) {
    if (vis[x] == 1) return x;
    vis[x] = 1;

    for (int y : a[x]) {
        if (y == p) continue;
        int res = func(y, x);
        if (res == -2) return -2;
        if (res >= 0) {
            vis[x] = 2;
            if (x == res) return -2;
            else return res;
        }
    }
    return -1;
}

int main() {
    input();
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    func(0, -1);
    
    for (int i = 0; i < n; i++) {
        if (vis[i] == 2) {
            dist[i] = 0;
            q.push(i);
        } 
        else dist[i] = -1;
    }

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int y : a[cur]) {
            if (dist[y] == -1) {
                q.push(y);
                dist[y] = dist[cur] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << dist[i] << " ";
}