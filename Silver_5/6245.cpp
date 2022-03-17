#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int score(string a) {
    if (a[0] == 'T') return 10;
    if (a[0] == 'J') return 11;
    if (a[0] == 'Q') return 12;
    if (a[0] == 'K') return 13;
    if (a[0] == 'A') return 1;
    return a[0] - '0';
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int main() {
    input();
    string a[8][8];
    int sc[8][8];

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        fill(sc[i], sc[i] + n, 0);
    }

    sc[n - 1][0] = score(a[n - 1][0]);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i == n - 1 && j == 0) continue;
            if (oob(i + 1, j) || oob(i, j - 1)) {
                if (oob(i + 1, j)) sc[i][j] = score(a[i][j]) + sc[i][j - 1];
                else sc[i][j] = score(a[i][j]) + sc[i + 1][j];
                continue;
            }
            sc[i][j] = score(a[i][j]) + max(sc[i + 1][j], sc[i][j - 1]);
        }
    }

    cout << sc[0][n - 1];
}