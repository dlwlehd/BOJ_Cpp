#include <bits/stdc++.h>
using namespace std;

int n;
int a[300005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int del = round(n * 0.15);

	fill(a, a + del, 0);
	fill(a + n - del, a + n, 0);

	double sum = 0;
	int avg_num = n - 2 * del;

	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	int avg = round(sum / avg_num);
	cout << avg;
}
