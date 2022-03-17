#include <bits/stdc++.h>
using namespace std;

int n;
char board[65][65];
string result = "";

bool same(int n, int x, int y) {

	char a = board[x][y];

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] != a) return false;
		}
	}

	return true;
}

void quadTree(int n, int x, int y) {
	if (n == 2) {

		if (same(n, x, y)) {
			result += board[x][y];
			return;
		}
		else {
			result += "(";
			result += board[x][y];
			result += board[x][y + 1];
			result += board[x + 1][y];
			result += board[x + 1][y + 1];
			result += ")";
		}

		return;
	}

	if (same(n, x, y)) {
		result += board[x][y];
		return;
	}

	else {
		int div = n / 2;

		result += "(";
		quadTree(div, x, y);
		quadTree(div, x, y + div);
		quadTree(div, x + div, y);
		quadTree(div, x + div, y + div);
		result += ")";
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

	quadTree(n, 0, 0);
	cout << result;
}