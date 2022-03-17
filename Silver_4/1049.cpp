#include <bits/stdc++.h>
using namespace std;

int n, m;
int pack[102];
double pack_div[102];
int a[102];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> pack[i] >> a[i];
	}

	for (int i = 0; i < m; i++) {
		pack_div[i] = pack[i] / 6;
	}

	sort(pack_div, pack_div + m);
	sort(pack, pack + m);
	sort(a, a + m);

	if (a[0] <= pack_div[0]) {
		cout << a[0] * n;
		return 0;
	}

	else {
		int result = 0;
		while (n > 6) {
			result += pack[0];
			n -= 6;
		}

		if (pack[0] <= n * a[0]) result += pack[0];
		else result += n * a[0];
		cout << result;
	}
}
