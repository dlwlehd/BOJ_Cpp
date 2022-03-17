#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n;
	cin >> n;
	int a[100001];

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}

	int t;
	cin >> t;

	int b[2000001];
	fill(b, b + 2000001, 0);

	int count = 0;

	for (int i = 0; i < n; i++) {

		if (t % a[i] == 0 && t / a[i] == 2) continue;

		if (b[t - a[i]] == 1) count++;
		b[a[i]] = 1;
	}

	cout << count;
}
