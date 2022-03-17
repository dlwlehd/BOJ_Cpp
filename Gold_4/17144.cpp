#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m, t, res = 0;
int board[52][52];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<pi> machine, dust;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void firstMachine() {
    auto [x, y] = machine[0];
    int temp[52][52];
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = board[i][j];
        }
    }

    temp[x][1] = 0;
    for (int i = 2; i < m; i++) temp[x][i] = board[x][i - 1];
    for (int i = x - 1; i >= 0; i--) temp[i][m - 1] = board[i + 1][m - 1];
    for (int i = m - 2; i >= 0; i--) temp[0][i] = board[0][i + 1];
    for (int i = 1; i < x; i++) temp[i][0] = board[i - 1][0];

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void secondMachine() {
    auto [x, y] = machine[1];
    int temp[52][52];
    for (int i = x; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = board[i][j];
        }
    }

    temp[x][1] = 0;
    for (int i = 2; i < m; i++) temp[x][i] = board[x][i - 1];
    for (int i = x + 1; i < n; i++) temp[i][m - 1] = board[i - 1][m - 1];
    for (int i = m - 2; i >= 0; i--) temp[n - 1][i] = board[n - 1][i + 1];
    for (int i = n - 2; i > x; i--) temp[i][0] = board[i + 1][0];

    for (int i = x; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

void spread() {
    int temp[52][52] = {0};

    for (auto d : dust) {
        int x = board[d.X][d.Y] / 5;
        for (int i = 0; i < 4; i++) {
            int nx = d.X + dx[i];
            int ny = d.Y + dy[i];
            if (oob(nx, ny) || board[nx][ny] == -1) continue;
            temp[d.X][d.Y] -= x;
            temp[nx][ny] += x;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] += temp[i][j];
            pi x = {i, j};
            if (x == machine[0] || x == machine[1]) continue;
            if (board[i][j] < 0) board[i][j] = 0;
        }
    }
}

int main() {
    input();
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) machine.push_back({i, j});
            if (board[i][j] > 0) dust.push_back({i, j});
        }
    }

    for (int i = 0; i < t; i++) {
        spread();
        firstMachine();
        secondMachine();
        dust.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0) dust.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res += board[i][j];
        }
    }

    cout << res + 2;
}