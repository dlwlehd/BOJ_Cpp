#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m, h;
int ladder[31][11];
int new_line;
int result = 1000000;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool Search(int start) {
    int next_col = start;

    for (int i = 1; i <= h; i++) {
        if (ladder[i][next_col] != 0) {
            next_col = ladder[i][next_col];
        }
    }

    if (next_col == start) {
        return true;
    }
    return false;
}

void make_line(int high, int cnt) {
    if (cnt == new_line) {
        for (int i = 1; i <= n; i++) {
            if (!Search(i)) {
                return;
            }
        }

        result = new_line;
        return;
    }

    for (int i = high; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (ladder[i][j] == 0 && ladder[i][j - 1] != j && ladder[i][j + 1] == 0) {
                ladder[i][j] = j + 1;
                ladder[i][j + 1] = j;

                make_line(i, cnt + 1);

                ladder[i][j] = 0;
                ladder[i][j + 1] = 0;
            }
        }
    }
}

int main() {
    input();
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        ladder[a][b] = b + 1;
        ladder[a][b + 1] = b;
    }

    while (true) {
        if (new_line > 3) {
            result = -1;
            break;
        }
        make_line(1, 0);
        if (result != 1000000) {
            break;
        }

        new_line += 1;
    }

    cout << result << "\n";
}