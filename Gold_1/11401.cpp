#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef unsigned long long ll;

const int MOD = 1e9 + 7;

ll fastMulti(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    ll n, k;
    cin >> n >> k;
    
    ll ans = 1;
    for (ll i = n - k + 1; i <= n; i++) ans = (ans * i) % MOD;
    
    ll b = 1;
	for (ll i = 1; i <= k; i++) b = (b * i) % MOD;
    
    ans = (ans * fastMulti(b, MOD - 2, MOD)) % MOD;
	cout << ans << '\n';
}