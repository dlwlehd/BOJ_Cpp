#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 9;
int dist[402][402];
int s[402];

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
        int u, v;
        cin >> u >> v;
        dist[u][v] = min(dist[u][v], 1);
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

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == 0 && dist[b][a] == 0) cout << "0\n";
        else if (dist[a][b] == 0 && dist[b][a] != 0) cout << "1\n";
        else cout << "-1\n";
    }
}