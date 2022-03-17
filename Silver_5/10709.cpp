#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

void debug() {
    freopen("E:\\BOJ_Cpp\\input.txt", "r", stdin);
    freopen("E:\\BOJ_Cpp\\output.txt", "w", stdout);
    freopen("E:\\BOJ_Cpp\\debug.txt", "w", stderr);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    debug();
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    char board[102][102];
    int ans[102][102];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            bool vis = 0;
            for (int k = j; k >= 0; k--) {
                if (board[i][k] == 'c') {
                    vis = 1;
                    break;
                } else cnt++;
            }
            if (!vis) ans[i][j] = -1;
            else ans[i][j] = cnt;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}