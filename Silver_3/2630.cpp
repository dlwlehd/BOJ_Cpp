#include <bits/stdc++.h>

using namespace std;

int n;
int bCnt = 0, wCnt = 0;
int board[130][130];
bool vis[130][130] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

bool check(int x, int y, int len) {
    int t = board[x][y];
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (board[i][j] != t) return false;
        }
    }
    return true;
}

void cnt(int x, int y, int len) {
    if (check(x, y, len)) {
        board[x][y] ? bCnt++ : wCnt++;
        return;
    }
    int a = len / 2;
    cnt(x, y, a);
    cnt(x, y + a, a);
    cnt(x + a, y, a);
    cnt(x + a, y + a, a);

}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cnt(0, 0, n);
    cout << wCnt << "\n" << bCnt;
}