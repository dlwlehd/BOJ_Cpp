#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int t;
    cin >> t;

    long long dp[32][32];
    for (int i = 0; i < 32; i++) {
        fill(dp[i], dp[i] + 32, 0);
    }

    for (int i = 0; i < 31; i++) {
        dp[i][0] = dp[i][i] = 1;
    }
    dp[1][1] = 1;
    for (int i = 1; i < 31; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] != 0) continue;
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    while (t--) {
        int n, m;
        cin >> m >> n;
        cout << dp[n][m] << "\n";
    }
}
