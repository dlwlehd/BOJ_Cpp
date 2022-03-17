#include <bits/stdc++.h>
using namespace std;

char board[51][51];
int n, m;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

bool oob(int y) {
    return y < 0 || y >= n;
}

int main(void) {
	input();

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {
        int mv = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'o') {
                    int x = 1;
                    while (true) {
                        if (oob(i + x)) break;
                        if (board[i + x][j] == '#' || board[i + x][j] == 'o') break;
                        board[i + x][j] = 'o';
                        board[i + x - 1][j] = '.';
                        x++;
                        mv++;
                    }
                }
            }
        }
        if (mv == 0) break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}