#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 9;
int dist[102][102];
int s[102];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v;
        dist[u][v] = min(dist[u][v], 1);
        dist[v][u] = min(dist[v][u], 1);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (dist[i][j] == INF ? 0 : dist[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += dist[i][j];
        }
        s[i] = sum;
    }

    int res = INF;
    int idx;
    for (int i = 1; i <= n; i++) {
        if (s[i] < res) {
            res = s[i];
            idx = i;
        }
    }
    cout << idx;
}