#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
typedef long long ll;

int Parent[10002];

int Find(int x) {
    return Parent[x] == x ? x : Parent[x] = Find(Parent[x]);
}

void Union(int a, int b) {
    a < b ? Parent[b] = a : Parent[a] = b;
}

struct Edge {
    int u, v, w;
    bool operator <(const Edge &x) { return w < x.w; }
};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    vector<Edge> a(m);
    for (int i = 1; i <= n; i++) Parent[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    
    sort(all(a));
    int sum = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        auto [u, v, w] = a[i];
        u = Find(u);
        v = Find(v);
        if (u == v) continue;
        Union(u, v);
        sum += w;
        cnt++;
        if (cnt == n - 1) break;
    }
    cout << sum;
}