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
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int tot = a[0];
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && tot < m) {
            en++;
            if (en != n) tot += a[en];
        }
        if (en == n) break;
        if (tot == m) cnt++;
        tot -= a[st];
    }
    cout << cnt;
}