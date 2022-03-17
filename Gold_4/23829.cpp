#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

void debug() {
    freopen("/root/projects/PS/input.txt", "r", stdin);
    freopen("/root/projects/PS/output.txt", "w", stdout);
    freopen("/root/projects/PS/debug.txt", "w", stderr);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    input();
    int n, q;
    ll ans = 0;
    cin >> n >> q;
    vector<ll> a(n + 1), psum(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + a[i];

    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        ll idx = upper_bound(a.begin() + 1, a.end(), x) - a.begin();

        ll u = psum[n] - psum[idx - 1], d = psum[idx - 1];
        ll ans = u - (n - idx + 1) * x;
        ans += (idx - 1) * x - d;
        cout << ans << "\n";
    }
}