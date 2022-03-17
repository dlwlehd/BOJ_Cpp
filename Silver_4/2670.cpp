#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int main() {
    input();
    int n;
    cin >> n;
    double res = -1;
    double a[10002], dp[10002];
    for (int i = 0; i < n; i++) cin >> a[i];

    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] * a[i], a[i]);
        res = max(res, dp[i]);
    }
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << res;
}