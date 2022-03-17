#include <bits/stdc++.h>
using namespace std;

int k, n;
char board[1000][25];
char up[26];
char down[26];
char q[25];
int qLine;
bool isAble = true;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		up[i] = 'A' + i;
		cin >> down[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			cin >> board[i][j];
			if (board[i][j] == '?') {
				qLine = i;
			}
		}
	}

	for (int i = 0; i < qLine; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (board[i][j] == '-') {
				char tmp = up[j];
				up[j] = up[j + 1];
				up[j + 1] = tmp;
			}
		}
	}
	for (int i = n - 1; i > qLine; i--) {
		for (int j = 0; j < k - 1; j++) {
			if (board[i][j] == '-') {
				char tmp = down[j];
				down[j] = down[j + 1];
				down[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < k - 1; i++) {

		if (up[i] == down[i]) {
			q[i] = '*';
		}

		else if (up[i] == down[i + 1] && up[i + 1] == down[i]) {
			q[i] = '-';
			char tmp = up[i];
			up[i] = up[i + 1];
			up[i + 1] = tmp;
		}
		else {
			isAble = false;
			break;
		}
	}

	if (isAble) {
		for (int i = 0; i < k - 1; i++) {
			cout << q[i];
		}
		cout << "\n";
	}

	else {
		for (int i = 0; i < k - 1; i++) {
			cout << 'x';
		}
		cout << "\n";
	}
}
