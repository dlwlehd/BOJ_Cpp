#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    ll lo = 1, hi = 1e10;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 1, cur = a[0];
        for (int i = 1; i < a.size(); i++) {
            if (a[i] - cur >= mid) {
                cnt++;
                cur = a[i];
            }
        }
        if (cnt >= c) lo = mid;
        else hi = mid;
    }
    cout << (lo + hi) / 2;
}