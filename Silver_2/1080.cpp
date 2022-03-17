#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
int board[52][52], res[52][52];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void flip(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            board[i][j] = (board[i][j] == 1 ? 0 : 1);
        }
    }
}

bool cmp() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != res[i][j]) return false;
        }
    }
    return true;
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            res[i][j] = s[j] - '0';
        }
    }
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (board[i][j] != res[i][j]) flip(i, j), ans++;
        }
    }
    if (cmp()) cout << ans;
    else cout << -1;
}