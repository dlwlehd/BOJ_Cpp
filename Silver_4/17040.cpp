#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, m;
    vector<int> x[102];
    vector<int> ans(102);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        x[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        for (int g = 1; g <= 4; g++) {
            bool flag = 1;
            for (int j = 0; j < x[i].size(); j++) {
                if (ans[x[i][j]] == g) flag = 0;
            }
            if (flag) {
                ans[i] = g;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i];
}