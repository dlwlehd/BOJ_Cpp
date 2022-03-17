#include <bits/stdc++.h>
using namespace std;

int n, mn = 987654321;
int board[11][11];

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main() {
	input();

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}

	do {
		int cost = 0;
		v.push_back(v[0]);
		bool flag = true;

		for (int i = 1; i <= n; i++) {
			int t = board[v[i - 1] - 1][v[i] - 1];
			if (t == 0) flag = false;
			cost += t;
		}

		v.pop_back();
		if (flag) mn = min(mn, cost);
		
	} while (next_permutation(v.begin(), v.end()));
	cout << mn;
}