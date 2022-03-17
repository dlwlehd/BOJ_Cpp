#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

const int mod = 1e9 + 3;
int n, k;
ll dp[1002][1002];

ll sol(int n, int k) {
    if ((n + 1) / 2 < k) return 0;
    if (k <= 1) return k ? n : 1;
    ll& ret = dp[n][k];
    if (ret != -1) return ret;
    return ret = (sol(n - 1, k) + sol(n - 2, k - 1)) % mod;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    if (k == 1) cout << n;
    else cout << (sol(n, k) - sol(n - 4, k - 2) + mod) % mod;
}