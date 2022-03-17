#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

struct SegTree {
    ll tree[1 << 21];
    int sz = 1 << 20;

    void construct() {
        for (int i = sz - 1; i > 0; i--) {
            tree[i] = (tree[i << 1] * tree[i << 1 | 1]) % mod;
        }
    }

    void Update(int i, int val) {
        --i |= sz;
        tree[i] = val;
        while (i >>= 1) {
            tree[i] = (tree[i << 1] * tree[i << 1 | 1]) % mod;
        }
    }

    ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
        if (R < nodeL || nodeR < L) return 1;
        if (L <= nodeL && nodeR <= R) return tree[nodeNum];
        int mid = nodeL + nodeR >> 1;
        return (query(L, R, nodeNum * 2, nodeL, mid) * query(L, R, nodeNum * 2 + 1, mid + 1, nodeR)) % mod;
    }

    ll query(int a, int b) {
        return query(a, b, 1, 1, sz);
    }
} ST;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("/root/projects/PS/input.txt", "r", stdin);
    freopen("/root/projects/PS/output.txt", "w", stdout);
}

int main() {
    input();
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> ST.tree[ST.sz + i];
    ST.construct();
    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) ST.Update(b, c);
        else cout << ST.query(b, c) << "\n";
    }
}