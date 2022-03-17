#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<int> a[100002];
int order[100002];
int parent[100002];
queue<int> q;
bool vis[100002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
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
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i] -= 1;
    }
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int m = 1;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            cout << 0;
            return 0;
        }

        int x = q.front(); q.pop();
        if (x != order[i]) {
            cout << 0;
            return 0;
        }
        
        int cnt = 0;
        for (int y : a[x]) {
            if (!vis[y]) {
                parent[y] = x;
                cnt++;
            }
        }

        for (int j = 0; j < cnt; j++) {
            if (m + j >= n || parent[order[m + j]] != x) {
                cout << 0;
                return 0;
            }
            q.push(order[m + j]);
            vis[order[m + j]] = 1;
        }
        m += cnt;
    }
    cout << 1;
}