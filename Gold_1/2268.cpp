#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

struct SegTree {
    int sz = 1 << 20;
    ll tree[1 << 21];

    void construct() {
        for (int i = sz - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
        if (R < nodeL || nodeR < L) return 0;
        if (L <= nodeL && nodeR <= R) return tree[nodeNum];
        int mid = nodeL + nodeR >> 1;
        return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
    }

    void Update(ll i, ll val) {
        --i |= sz;
        tree[i] = val;
        while (i >>= 1) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    ll query(ll a, ll b) {
        return query(a, b, 1, 1, sz);
    }
} ST;

void debug() {
    freopen("/root/projects/PS/input.txt", "r", stdin);
    freopen("/root/projects/PS/output.txt", "w", stdout);
    freopen("/root/projects/PS/debug.txt", "w", stderr);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    debug();
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) ST.tree[ST.sz + i] = 0;
    ST.construct();
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            if (b > c) swap(b, c);
            cout << ST.query(b, c) << "\n";
        }
        else ST.Update(b, c);
    }
}