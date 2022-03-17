#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i: v) cin >> i;
	sort(v.begin(), v.end());
	
	int mn = INT_MAX, a, b;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(v.begin(), v.end(), -v[i]);
		for (int j = -1; j <= 1; j++) {
			auto jt = it + j;
			if (jt < v.begin() || jt >= v.end() || jt == v.begin() + i) continue;
			const int diff = abs(v[i] + *jt);
			if (mn > diff) mn = diff, a = v[i], b = *jt;
		}
	}
	
	if (a > b) swap(a, b);
	cout << a << " " << b;
}