#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
typedef long long ll;

ll dp[1002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int t;
    cin >> t;
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 1000; i++) {
        ll x = 0, idx = 0;
        while (true) {
            if (i - idx < 0) break;
            if (i - idx >= 0) x += dp[idx / 2];
            idx += 2;
        }
        dp[i] = x;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}