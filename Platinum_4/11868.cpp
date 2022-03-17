#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res ^= a[i];
    }
    if (res == 0)
        cout << "cubelover";
    else
        cout << "koosaga";
}