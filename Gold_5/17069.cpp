#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;
ll n, board[33][33], dp[33][33][3];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> board[i][j];
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n; j++) {
            if ((i == 1 && j <= 2) || board[i][j]) continue;
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
            dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][1];
            if (board[i - 1][j] == 0 && board[i][j - 1] == 0) {
                dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << '\n';
}
