#include <bits/stdc++.h>

using namespace std;

int board[9][9];
bool row[9][9] = {0}, col[9][9] = {0}, sq[9][9] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void dfs(int cnt) {
    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    int x = cnt / 9;
    int y = cnt % 9;
    if (board[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (row[x][i] == false && col[y][i] == false && sq[(x / 3) * 3 + (y / 3)][i] == false) {
                row[x][i] = true;
                col[y][i] = true;
                sq[(x / 3) * 3 + (y / 3)][i] = true;
                board[x][y] = i;
                dfs(cnt + 1);
                board[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                sq[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    } else dfs(cnt + 1);
}

int main() {
    input();
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            int x = s[j] - '0';
            board[i][j] = x;
            if (x != 0) {
                row[i][x] = 1;
                col[j][x] = 1;
                sq[(i / 3) * 3 + (j / 3)][x] = 1;
            }
        }
    }
    dfs(0);
}