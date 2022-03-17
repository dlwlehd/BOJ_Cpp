#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int main() {
    input();
    int dp[1002];
    int n;
    cin >> n;
    fill(dp, dp + n, 0);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= n; i++) {
        if (dp[i - 1]) dp[i] = 0;
        else dp[i] = 1;
    }
    cout << (dp[n] ? "SK" : "CY");
}