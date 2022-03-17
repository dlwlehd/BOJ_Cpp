#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool ok(vector<ll> a, ll x) {
	ll cnt = 0;
	for (int i = 0; i < a.size(); i++) cnt += x / a[i];
	if (cnt >= m) return true;
	return false;
}

int main() {
	input();
	cin >> n >> m;
	vector<ll> a(n);
	for (auto &i: a) cin >> i;
	ll lo = 0, hi = *max_element(a.begin(), a.end()) * m;
	
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (ok(a, mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}