#include <bits/stdc++.h>

using namespace std;
int n, m;
int cnt = 0;
bool check[205][205];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		check[x][y] = check[y][x] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (check[i][j]) continue;

			for (int k = j + 1; k <= n; k++) {
				if (check[i][k] || check[j][k]) continue;
				cnt++;
			}
		}
	}
	cout << cnt;
}