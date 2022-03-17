#include <bits/stdc++.h>
using namespace std;

int n;
int arr[50002];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		int temp = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			int x = i - j * j;
			temp = min(temp, arr[x]);
		}
		arr[i] = temp + 1;
	}

	cout << arr[n];
}