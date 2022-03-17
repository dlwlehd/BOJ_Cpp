#include <bits/stdc++.h>
using namespace std;

int n, res = 987654321;
int board[11][11];
bool vis[11];
vector<int> temp;

void func(int idx, int start, int cur, int tot) {

	if (idx == n && start == cur) {
		res = min(res, tot);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (board[cur][i] == 0) continue;

		if (!vis[i] && board[cur][i] > 0) {
			vis[i] = 1;
			tot += board[cur][i];
			if (res >= tot) {
				func(idx + 1, start, i, tot);
			}
			vis[i] = 0;
			tot -= board[cur][i];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		func(0, i, i, 0);
	}

	cout << res;
}