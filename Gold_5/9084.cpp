#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int a[22], dp[10002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
	input();
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> m;
		fill(dp, dp + m + 1, 0);
		dp[0] = 1;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				if (j - a[i] >= 0) dp[j] += dp[j - a[i]];
			}
		}
		
		cout << dp[m] << "\n";
	}
}
