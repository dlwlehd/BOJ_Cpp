#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

ll n, p, q, x, y;
ll dp[10000001];

ll sol(ll n) {
	if (n <= 0) return 1;
	if (n <= 10000000) {
		if (dp[n] != -1) return dp[n];
		else return dp[n] = sol(n / p - x) + sol(n / q - y);
	}
	return sol(n / p - x) + sol(n / q - y);
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    memset(dp, -1, sizeof(dp));
    cin >> n >> p >> q >> x >> y;
    cout << sol(n);
}