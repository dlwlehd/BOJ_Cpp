#include <bits/stdc++.h>
using namespace std;

int n, s, c;
int d[1002][1002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main() {
    input();

    cin >> n;
    memset(d, -1, sizeof(d));

    queue<pair<int, int>> q;
    q.push({ 1,0 });
    d[1][0] = 0;
    while (!q.empty()) {
        int s, c;
        tie(s, c) = q.front(); q.pop();
        if (d[s][s] == -1) {
            d[s][s] = d[s][c] + 1;
            q.push({ s,s });
        }
        if (s + c <= n && d[s + c][c] == -1) {
            d[s + c][c] = d[s][c] + 1;
            q.push({s + c, c});
        }
        if (s - 1 >= 0 && d[s - 1][c] == -1) {
            d[s - 1][c] = d[s][c] + 1;
            q.push({ s - 1, c });
        }
    }
    int ans = -1;
    for (int i = 0; i <= n; i++) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    cout << ans;
}