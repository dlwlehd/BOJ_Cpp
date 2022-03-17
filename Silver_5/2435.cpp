#include <bits/stdc++.h>
using namespace std;

int n, k;
int res = -987654321, tot = 0;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main(void) {

	input();
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i <= n - k; i++) {
		tot = 0;
		for (int j = 0; j < k; j++) {
			tot += v[i + j];
		}
		res = max(res, tot);
	}

	cout << res;
}