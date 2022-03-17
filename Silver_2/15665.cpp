#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int in[10];
bool isused[10];

void func(int k) {

	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}

	int before = -1;

	for (int i = 0; i < n; i++) {
		if (before != in[i]) {
			before = in[i];
			arr[k] = in[i];
			func(k + 1);
		}
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

	func(0);
}