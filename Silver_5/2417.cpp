#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    ll n, lo = 0, hi = LLONG_MAX;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        mid * mid >= n ? hi = mid : lo = mid;
    }
    cout << hi;
}