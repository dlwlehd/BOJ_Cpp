#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define value cur.first
#define time cur.second

int parent[100002];
bool vis[100002];
int n, k;
queue<pair<int,int>> Q;
vector<int> path;

void bfs() {

	fill(vis, vis + 100001, 0);
	Q.push({ n,0 });
	vis[n] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		vis[value] = 1;

		if (value == k) {
			int idx = value;
			while (idx != n) {
				path.push_back(idx);
				idx = parent[idx];
			}
			cout << time << "\n";
		}

		if (value - 1 >= 0 && value - 1 <= 100002 && !vis[value - 1]) {
			Q.push({ value - 1,time + 1 });
			vis[value - 1] = 1;
			parent[value - 1] = value;
		}
		if (value + 1 >= 0 && value + 1 <= 100002 && !vis[value + 1]) {
			Q.push({ value + 1,time + 1 });
			vis[value + 1] = 1;
			parent[value + 1] = value;
		}
		if (value * 2 >= 0 && value * 2 <= 100002 && !vis[value * 2]) {
			Q.push({ value * 2,time + 1 });
			vis[value * 2] = 1;
			parent[value * 2] = value;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs();
	cout << n << " ";
	for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";

}
