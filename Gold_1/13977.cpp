#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef unsigned long long ll;

const int MOD = 1e9 + 7;
ll fac[4000001]{ 1 }, inv[4000001];

ll mInv(ll a, ll b) {
	if (a == 0 && b == 1) return 0;
	if (a == 1) return 1;
	return b - mInv(b % a, a) * b / a;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    for (ll i = 1; i <= 4000000; i++) fac[i] = fac[i - 1] * i % MOD;
	inv[4000000] = mInv(fac[4000000], MOD);
	for (ll i = 3999999; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    
	int t; 
    cin >> t;
	while (t--) {
		ll n, r; cin >> n >> r;
		if (r && r != n) cout << fac[n] * inv[r] % MOD * inv[n - r] % MOD << '\n';
		else cout << 1 << '\n';
	}
}