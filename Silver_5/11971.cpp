#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> road(n), speed(m);
    for (auto &i: road) cin >> i.first >> i.second;
    for (auto &i: speed) cin >> i.first >> i.second;

    int r[101], s[101];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = idx; j < idx + road[i].first; j++) {
            r[j] = road[i].second;
        }
        idx += road[i].first;
    }

    idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = idx; j < idx + speed[i].first; j++) {
            s[j] = speed[i].second;
        }
        idx += speed[i].first;
    }

    int res = 0;
    for (int i = 0; i < 100; i++) {
        if (s[i] > r[i]) res = max(res, s[i] - r[i]);
    }
    cout << res;
}