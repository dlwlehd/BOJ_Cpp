#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[7][7];
int res = 987654321;
int dy[] = {-1,0,1};

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

bool oob (int y) {
    return y < 0 || y >= m;
}

void func(int d, int x, int y, int tot) {
    if (x == n) {
        res = min(tot,res);
        return;
    }

    for (int dir = 0; dir < 3; dir++) {
        if (dir == d) continue;

        int ny = y + dy[dir];
        if (oob(ny)) continue;

        func(dir, x + 1, ny, tot + board[x + 1][ny]);
    }

}

int main(void) {

	input();
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        func(-1,0,i,board[0][i]);
    }
    cout << res;
}