#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[20002];
int b[20002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		int cnt = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		sort(a, a + n, greater<>());
		sort(b, b + m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] <= b[j]) break;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}