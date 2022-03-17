#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
typedef long long ll;

int n, s, m;
int dp[52][1002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> s >> m;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + m + 1, -1);
    }
    dp[0][s] = 1;
    
    for (int i = 1; i <= n; i++) {
        int idx = a[i - 1];
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j] != -1) {
                if (j + idx <= m) dp[i][j + idx] = 1;
                if (j - idx >= 0) dp[i][j - idx] = 1;
            }
        }
    }
    
    for (int i = m; i >= 0; i--) {
        if (dp[n][i] != -1) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}