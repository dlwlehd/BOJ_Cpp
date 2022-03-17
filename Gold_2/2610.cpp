#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 9;
int n, m;
int dist[102][102];
bool vis[102];
int board[102][102];
int s[102];
vector<int> res;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

void floyd(vector<int> group) {
    int size = group.size();
    if (size == 1) {
        res.push_back(group[0]);
        return;
    }
    int d[101][101];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) d[i][j] = 0;
            else if (board[group[i]][group[j]] == true) d[i][j] = 1;
            else d[i][j] = size + 1;
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int rep;
    int tmp = size + 1;

    for (int i = 0; i < size; i++) {
        int dis = 0;
        for (int j = 0; j < size; j++) {
            dis = max(dis, d[i][j]);
        }
        if (dis < tmp) {
            tmp = dis;
            rep = group[i];
        }
    }
    res.push_back(rep);
}


void dfs(int cur) {
    queue<int> q;
    vector<int> group;
    group.push_back(cur);
    q.push(cur);
    vis[cur] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (vis[i] || !board[i][cur]) continue;
            vis[i] = 1;
            q.push(i);
            group.push_back(i);
        }
    }
    floyd(group);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        board[u][v] = board[v][u] = 1;
        dist[u][v] = dist[v][u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i: res) cout << i << "\n";
}