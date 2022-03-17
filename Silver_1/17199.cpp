#include <bits/stdc++.h>

using namespace std;
vector<int> v[102];
int vis[102];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void dfs(int cur) {
    vis[cur] = 1;
    for (int i = 0; i < v[cur].size(); i++) {
        int nxt = v[cur][i];
        if (!vis[nxt]) dfs(nxt);
    }
}

int main() {
    input();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        fill(vis, vis + n + 1, 0);
        dfs(i);
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}