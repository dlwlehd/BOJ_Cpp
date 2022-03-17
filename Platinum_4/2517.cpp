#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

template<size_t sz>
struct SegTree {
	vector<int> tree;
	SegTree() : tree(sz << 1) {}
	void update(int i, int val) {
		--i |= sz; tree[i] = val;
		while (i >>= 1) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	}
	int query(int l, int r) {
		int ret = 0;
		--l |= sz, --r |= sz;
		while (l <= r) {
			if (l & 1) ret += tree[l++];
			if (~r & 1) ret += tree[r--];
			l >>= 1, r >>= 1;
		}
		return ret;
	}
};

SegTree<1 << 20> ST;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	auto w = v;
	sort(w.begin(), w.end()), w.erase(unique(w.begin(), w.end()), w.end());
	for (auto& i : v) i = lower_bound(w.begin(), w.end(), i) - w.begin() + 1;
	for (int i = 0; i < n; i++) {
		cout << i - ST.query(1, v[i]) + 1 << '\n';
		ST.update(v[i], 1);
	}
}
