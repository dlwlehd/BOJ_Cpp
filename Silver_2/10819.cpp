#include <bits/stdc++.h>
using namespace std;

int n, mx = 0;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main() {
	input();

	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	do {
		int calc = 0;

		for (int i = 1; i < n; i++) {
			calc += abs(a[i - 1] - a[i]);
		}

		mx = max(mx, calc);
	} while (next_permutation(a.begin(), a.end()));

	cout << mx;
}