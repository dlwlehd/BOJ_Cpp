#include <bits/stdc++.h>
using namespace std;

int board[8][7];
int domino[28][2];
bool vis_d[28];
bool vis[8][7];
int cnt = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void func(int x, int y) {
    if (y == 7) {
        y = 0;
        x++;
    }

    if (x == 8) {
        cnt++;
        return;
    }

    if (!vis[x][y]) {
        if (x + 1 < 8 && !vis[x + 1][y]) {
            int a = board[x][y];
            int b = board[x + 1][y];

            if (a > b) {
                swap(a, b);
            }

            int idx = 6;
            int row = 0;
            for (int i = 0; i < a; i++) {
                row += idx;
                idx--;
            }
            row += b;

            if (!vis_d[row]) {
                vis_d[row] = 1;
                vis[x][y] = 1;
                vis[x + 1][y] = 1;
                func(x, y + 1);
                vis_d[row] = 0;
                vis[x][y] = 0;
                vis[x + 1][y] = 0;
            }
        }

        if (y + 1 < 7 && !vis[x][y + 1]) {
            int a = board[x][y];
            int b = board[x][y + 1];

            if (a > b) {
                swap(a, b);
            }

            int idx = 6;
            int row = 0;
            for (int i = 0; i < a; i++) {
                row += idx;
                idx--;
            }
            row += b;

            if (!vis_d[row]) {
                vis_d[row] = 1;
                vis[x][y] = 1;
                vis[x][y + 1] = 1;
                func(x, y + 1);
                vis_d[row] = 0;
                vis[x][y] = 0;
                vis[x][y + 1] = 0;
            }
        }
    }
    else func(x, y + 1);
}

int main(void) {
    input();
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 7; j++) {
            int x = s[j] - '0';
            board[i][j] = x;
            vis[i][j] = 0;
        }
    }

    int idx = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = i; j < 7; j++) {
            domino[idx][0] = i;
            domino[idx][1] = j;
            idx++;
            vis_d[idx] = 0;
        }
    }
    func(0, 0);
    cout << cnt;
}