#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[500001];

	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		a[i] = b;
	}
	sort(a, a + n);

	int t;
	cin >> t;

	while (t-- > 0) {
		int x;
		cin >> x;

		if (binary_search(a, a + n, x) == true) cout << 1 << " ";
		else cout << 0 << " ";
	}
}