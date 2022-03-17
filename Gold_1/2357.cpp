#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;

struct MinSegTree {
    int sz = 1 << 20;
    int tree[1 << 21];

    void construct() {
        for (int i = sz - 1; i > 0; i--) tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int L, int R, int nodeNum, int nodeL, int nodeR) {
        if (R < nodeL || nodeR < L) return INF;
        if (L <= nodeL && nodeR <= R) return tree[nodeNum];
        int mid = nodeL + nodeR >> 1;
        return min(query(L, R, nodeNum * 2, nodeL, mid), query(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
    }

    int query(int a, int b) {
        return query(a, b, 1, 1, sz);
    }
} minST;

struct MaxSegTree {
    int sz = 1 << 20;
    int tree[1 << 21];

    void construct() {
        for (int i = sz - 1; i > 0; i--) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int L, int R, int nodeNum, int nodeL, int nodeR) {
        if (R < nodeL || nodeR < L) return -INF;
        if (L <= nodeL && nodeR <= R) return tree[nodeNum];
        int mid = nodeL + nodeR >> 1;
        return max(query(L, R, nodeNum * 2, nodeL, mid), query(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
    }

    int query(int a, int b) {
        return query(a, b, 1, 1, sz);
    }
} maxST;

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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        minST.tree[minST.sz + i] = x;
        maxST.tree[maxST.sz + i] = x;
    }

    minST.construct();
    maxST.construct();

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << minST.query(a, b) << " " << maxST.query(a, b) << "\n";
    }
}