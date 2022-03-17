#include <bits/stdc++.h>
using namespace std;

int t, res = 987654321;
int board[3][3];
bool vis[513];

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

void reverse(int a, int b) {
	// 1이면 세로 뒤집기 0이면 가로 뒤집기
	if (a == 0) {
		for (int i = 0; i < 3; i++) {
			board[b][i] = (board[b][i] == 1 ? 0 : 1);
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			board[i][b] = (board[i][b] == 1 ? 0 : 1);
		}
	}
}

void reverse_c(int dir) {
	for (int i = 0; i < 3; i++) {
		if (dir == 0) {
			board[i][i] = (board[i][i] == 1 ? 0 : 1);
		}
		else {
			board[i][2 - i] = (board[i][2 - i] == 1 ? 0 : 1);
		}
	}
}

bool check() {
	bool flag = true;
	int x = board[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != x) flag = false;
		}
	}
	return flag;
}

void func(int cnt) {
	if (cnt >= 100) {
		res = -1;
		return;
	}

	if (check()) {
		res = cnt;
		return;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			reverse(i, j);

		}
	}
}

int to_int() {
	int now = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			now = now * 2 + board[i][j];
		}
	}
	return now;
}

void to_board(int num) {
	for (int i = 2; i >= 0; i--) {
		for (int j = 2; j >= 0; j--) {
			board[i][j] = num % 2;
			num /= 2;
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	int first = to_int();
	q.push({ first,0 });
	vis[first] = 1;

	while (!q.empty()) {
		auto x = q.front(); q.pop();
		to_board(x.first);

		if (check()) {
			return x.second;
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				reverse(i, j);
				int next = to_int();
				if (!vis[next]) {
					vis[next] = 1;
					q.push({ next,x.second + 1 });
				}
				reverse(i, j);
			}
		}

		for (int i = 0; i < 2; i++) {
			reverse_c(i);
			int next = to_int();
			if (!vis[next]) {
				vis[next] = 1;
				q.push({ next,x.second + 1 });
			}
			reverse_c(i);
		}
	}

	return -1;
}

void print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}

int main(void) {

	input();
	cin >> t;

	while (t--) {
		fill(vis, vis + 513, 0);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char x;
				cin >> x;
				if (x == 'H') board[i][j] = 0;
				else board[i][j] = 1;
			}
		}
		
		cout << bfs() << "\n";
	}
}