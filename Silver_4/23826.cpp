#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

struct w {
    int x, y, e;
};

int weight(w a, w b) {
    return max(0, a.e - (abs(a.x - b.x) + abs(a.y - b.y)));
}

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
    int n;
    cin >> n;
    vector<w> a(n + 1);
    int res = 0;
    for (auto &i : a) cin >> i.x >> i.y >> i.e;

    for (int i = 1; i <= n; i++) {
        int pub, sum = 0;
        pub = weight(a[0], a[i]);
        if (pub == 0) continue;

        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            sum += weight(a[j], a[i]);
        }
        sum += a[i].e;
        res = max(res, pub - sum);
    }

    if (res == 0) cout << "IMPOSSIBLE";
    else cout << res;
}