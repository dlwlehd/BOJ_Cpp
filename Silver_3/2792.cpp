#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll& i : a) cin >> i;

    ll lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll sum = 0;
        for (auto i : a) {
            sum += (i - 1) / mid + 1;
        }
        (sum <= n ? hi : lo) = mid;
    }
    cout << hi;
}