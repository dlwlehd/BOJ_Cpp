#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
typedef long long ll;

int Parent[100002];

int Find(int x) {
    return Parent[x] == x ? x : Parent[x] = Find(Parent[x]);
}

void Union(int a, int b) {
    a < b ? Parent[b] = a : Parent[a] = b;
}

struct Edge {
    int u, v;
    double w;
    bool operator <(const Edge &x) { return w < x.w; }
};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n, m;
    cin >> n;
    vector<pair<double, double>> p(n);
    vector<Edge> a;
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;        
    for (int i = 0; i < n; i++) Parent[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = sqrt(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2));
            a.push_back({i, j, dist});
        }
    }
    
    sort(all(a));
    double sum = 0, cnt = 0;
    for (int i = 0; i < sz(a); i++) {
        auto [u, v, w] = a[i];
        u = Find(u);
        v = Find(v);
        if (u == v) continue;
        Union(u, v);
        sum += w;
        cnt++;
        if (cnt == n - 1) break;
    }
    
    cout << fixed;
    cout.precision(2);
    cout << sum;
}