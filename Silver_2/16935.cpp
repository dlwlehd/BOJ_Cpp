#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;

int n, m, r;
int board[102][102];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void upDown() {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            swap(board[i][j], board[n - i - 1][j]);
        }
    }
}

void leftRight() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            swap(board[i][j], board[i][m - j - 1]);
        }
    }
}

void rotate() {
    int t[102][102];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[i][j] = board[i][j];
        }
    }
    swap(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = t[m - 1 - j][i];
        }
    }
}

void halfMove() {
    int t[102][102];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            t[i][j + m / 2] = board[i][j];
        }
    }

    for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            t[i - n / 2][j] = board[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) {
            t[i + n / 2][j] = board[i][j];
        }
    }

    for (int i = n / 2; i < n; i++) {
        for (int j = m / 2; j < m; j++) {
            t[i][j - m / 2] = board[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = t[i][j];
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    input();
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    vector<int> op(r);
    for (int &i: op) cin >> i;

    for (int i: op) {
        if (i == 1) upDown();
        if (i == 2) leftRight();
        if (i == 3) {
            rotate();
        }
        if (i == 4) {
            rotate();
            rotate();
            rotate();
        }
        if (i == 5) halfMove();
        if (i == 6) {
            halfMove();
            halfMove();
            halfMove();
        }
    }
    print();
}