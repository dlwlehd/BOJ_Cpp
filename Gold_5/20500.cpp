#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n;
    int dp[1600][3];
    cin >> n;

    dp[2][0] = dp[2][1] = 1;
    for (int i = 3; i <= 1515; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = (dp[i - 1][(j + 1) % 3] + dp[i - 1][(j + 2) % 3]) % 1000000007;
        }
    }
    cout << dp[n][0];
}