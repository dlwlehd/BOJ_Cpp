#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

ll x, y;

void debug() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    debug();
}

ll calc(ll x, ll y) {
    return 100 * y / x;
}

bool check(ll k) {
    return calc(x, y) != calc(x + k, y + k);
}

int main() {
    input();
    cin >> x >> y;
    ll lo = 1, hi = 1e9;

    if (calc(x, y) >= 99) {
        cout << -1;
        return 0;
    }

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (!check(mid)) lo = mid;
        else hi = mid;
    }

    cout << hi;
}
