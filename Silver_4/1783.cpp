#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    ll n, m;
    cin >> n >> m;
    if (n == 1) cout << 1;
    else if (n == 2) cout << min<ll>(4, (m + 1) / 2);
    else {
        if (m <= 6) cout << min<ll>(4, m);
        else cout << m - 2;
    }
}