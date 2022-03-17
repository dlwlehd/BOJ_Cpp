#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main() {
    input();
    int n, m;
    int mn = 2 * 1e9 + 7;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(all(a));
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && a[en] - a[st] < m) en++;
        if (en == n) break;
        mn = min(mn, a[en] - a[st]);
    }
    cout << mn;
}