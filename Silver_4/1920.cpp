#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[100001];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int m;
	cin >> m;
	int in;

	for (int i = 0; i < m; i++) {
		cin >> in;
		cout << binary_search(a, a + n, in) << "\n";
	}
}