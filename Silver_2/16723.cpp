#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

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
    ll n;
    cin >> n;
    vector<ll> a;
    ll idx = 1;
    for (int i = 0; i < 31; i++) {
        a.push_back(idx);
        idx *= 2;
    }
    vector<ll> b(a.size());
    for (int i = 0; i < a.size(); i++) {
        b[i] = n / a[i];
    }

    for (int i = b.size() - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            b[j] -= b[i];
        }
    }

    ll ans = 0;

    idx = 1;
    for (int i = 0; i < b.size(); i++) {
        ans += idx * b[i];
        idx *= 2;
    }

    cout << ans * 2;
}