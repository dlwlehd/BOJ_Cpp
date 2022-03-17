#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int func(int start, vector<int> a) {
    int cnt = 0;
    vector<bool> vis(n, 0);
    queue<pair<int, int> > q;
    q.push({start, 1});
    vis[start] = 1;
    while (!q.empty()) {
        int idx = q.front().first;
        int range = q.front().second;
        q.pop();
        for (int i = 0; i < n; i++) {
            if (i != idx && !vis[i] && abs(a[i] - a[idx]) <= range) {
                q.push({i, range + 1});
                vis[i] = 1;
            }
        }
    }
    for (auto i: vis) if (i) cnt++;
    return cnt;
}

int main() {
    input();
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());

    int res = -1;
    for (int i = 0; i < n; i++) {
        res = max(res, func(i, a));
    }
    cout << res;
}