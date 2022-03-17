#include <bits/stdc++.h>
using namespace std;

int n, m, sum;
int v[100], w[100], dp[10001]; 

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
	input();
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++) sum += w[i];
	for (int i = 0; i < n; i++) for (int j = sum; j >= w[i]; j--) {
		dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	}
	for (int i = 0; i <= sum; i++) 
		if (dp[i] >= m) {
		cout << i << '\n';
		return 0;
	}
}
