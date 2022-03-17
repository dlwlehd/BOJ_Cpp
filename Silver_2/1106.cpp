#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int c, n;
    int d[1200];
    cin >> c >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    fill(d, d + 1200, INF);
    d[0] = 0;
    for (int i = 1; i <= 1200; i++) {
        for (int j = 0; j < a.size(); j++) {
            int x = a[j].first, y = a[j].second;
            if (i - y >= 0) d[i] = min(d[i - y] + x, d[i]);
        }
    }
    int res = d[c];
    for (int i = c; i < 1200; i++) {
        res = min(res, d[i]);
    }
    cout << res;
}