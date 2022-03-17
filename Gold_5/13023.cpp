#include <bits/stdc++.h>
using namespace std;

int n, m;
bool a[2002][2002]; // 인접 행렬
vector<int> g[2002]; // 인접 리스트
vector<pair<int, int>> edges; // 간선 리스트

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	input();

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		edges.push_back({ from,to });
		edges.push_back({ to,from });
		a[from][to] = 1;
		a[to][from] = 1;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	m *= 2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // A -> B
            int A = edges[i].first;
            int B = edges[i].second;
            // C -> D
            int C = edges[j].first;
            int D = edges[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            // B -> C
            if (!a[B][C]) {
                continue;
            }
            // D -> E
            for (int E : g[D]) {
                if (A == E || B == E || C == E || D == E) {
                    continue;
                }
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
