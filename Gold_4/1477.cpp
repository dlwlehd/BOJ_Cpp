#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n, m, l;
vector<int> a;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

bool check(int mid) {
    int cnt = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        int d = a[i + 1] - a[i];
        cnt += d / mid;
        if (d % mid == 0) cnt--;
    }
    if (cnt <= m) return true;
    return false;
}

int main() {
    input();
    cin >> n >> m >> l;
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(all(a));
    a.push_back(l);
    int lo = 0, hi = l;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi;
}