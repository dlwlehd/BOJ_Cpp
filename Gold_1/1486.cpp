#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> p;

const int INF = int(1e9);
int n, m, T, D;
int board[25][25], dist[625], dist2[625];
vector<p> adj[625], adj2[625];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    cin >> n >> m >> T >> D;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        char c; cin >> c;
        if (c <= 'Z') board[i][j] = c - 'A';
        else board[i][j] = c - 'a' + 26;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (abs(board[nx][ny] - board[i][j]) > T) continue;
            if (board[i][j] < board[nx][ny]) {
                adj[i * m + j].push_back({ (board[nx][ny] - board[i][j]) * (board[nx][ny] - board[i][j]), nx * m + ny });
                adj2[i * m + j].push_back({ 1, nx * m + ny });
            }
            else if (board[i][j] == board[nx][ny]) {
                adj[i * m + j].push_back({ 1, nx * m + ny });
                adj2[i * m + j].push_back({ 1, nx * m + ny });
            }
            else {
                adj[i * m + j].push_back({ 1, nx * m + ny });
                adj2[i * m + j].push_back({ (board[nx][ny] - board[i][j]) * (board[nx][ny] - board[i][j]), nx * m + ny });
            }
        }
    }
    priority_queue<p, vector<p>, greater<p>> PQ;
    fill(dist, dist + n * m, INF);
    dist[0] = 0;
    PQ.push({ dist[0], 0 });
    while (!PQ.empty()) {
        auto [cost, idx] = PQ.top(); PQ.pop();
        if (dist[idx] != cost) continue;
        for (auto [ncost, nidx] : adj[idx]) {
            if (dist[nidx] > cost + ncost) {
                dist[nidx] = cost + ncost;
                PQ.push({ dist[nidx], nidx });
            }
        }
    }
	
    fill(dist2, dist2 + n * m, INF);
    dist2[0] = 0;
    PQ.push({ dist2[0], 0 });
    while (!PQ.empty()) {
        auto [cost, idx] = PQ.top(); PQ.pop();
        if (dist2[idx] != cost) continue;
        for (auto [ncost, nidx] : adj2[idx]) {
            if (dist2[nidx] > cost + ncost) {
                dist2[nidx] = cost + ncost;
                PQ.push({ dist2[nidx], nidx });
            }
        }
    }
	
    int ans = board[0][0];
    for (int i = 1; i < n * m; i++) if (dist[i] + dist2[i] <= D) ans = max(ans, board[i / m][i % m]);
    cout << ans;
}
