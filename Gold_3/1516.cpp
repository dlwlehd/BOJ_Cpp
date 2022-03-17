#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

int n, indegree[1002], t[1002], res[1002] = {0};
vector<int> adj[1002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> t[i];
        while (true) {
            cin >> x;
            if (x == -1) break;
            adj[x].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            res[i] = t[i];
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int next: adj[cur]) {
            indegree[next]--;
            res[next] = max(res[cur] + t[next], res[next]);
            if (indegree[next] == 0) q.push(next);
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << "\n";
}