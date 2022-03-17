#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int main() {
    input();
    int r, c, w;
    cin >> r >> c >> w;
    long long dp[32][32];
    for (int i = 0; i < 32; i++) {
        fill(dp[i], dp[i] + 32, 0);
    }
    for (int i = 0; i < 32; i++) {
        dp[i][0] = dp[i][i] = 1;
    }
    for (int i = 2; i < 32; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    r--; c--;
    int idx = 1;
    long long sum = 0;
    for (int i = r; i < r + w; i++) {
        for (int j = c; j < c + idx; j++) {
            sum += dp[i][j];
        }
        idx++;
    }
    cout << sum;
}