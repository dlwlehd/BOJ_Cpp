#include <bits/stdc++.h>
using namespace std;

int n;
int board[2200][2200];
int result_minus = 0;
int result_zero = 0;
int result_plus = 0;


bool same(int n, int x, int y) {

	int a = board[x][y];

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] != a) return false;
		}
	}

	return true;
}

void cut(int n, int x, int y) {
	if (n == 1) {

		int t = board[x][y];

		if (t == 1) {
			result_plus++;
		}
		else if (t == 0) {
			result_zero++;
		}
		else if (t == -1) {
			result_minus++;
		}

		return;
	}

	if (same(n, x, y)) {

		int t = board[x][y];

		if (t == 1) {
			result_plus++;
		}
		else if (t == 0) {
			result_zero++;
		}
		else if (t == -1) {
			result_minus++;
		}

		return;
	}
	else {

		int div = n / 3;

		for (int i = 0; i < n; i += div) {
			for (int j = 0; j < n; j += div) {
				cut(div, x + i, y + j);
			}
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	cut(n, 0, 0);

	cout << result_minus << "\n";
	cout << result_zero << "\n";
	cout << result_plus << "\n";
}