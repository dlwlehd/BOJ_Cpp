#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int in[10];
bool isused[10];

void func(int x, int k) {

	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << in[arr[i]] << ' ';
		cout << "\n";
		return;
	}

	for (int i = x; i < n; i++) {
		arr[k] = i;
		func(i, k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}

	sort(in, in + n);

	func(0, 0);
}