#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int a[4002], b[4002], c[4002], d[4002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
	input();
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(c[i] + d[j]);
		}
	}
	sort(v.begin(), v.end());
    
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto cur = a[i] + b[j];
			auto [lo, hi] = equal_range(v.begin(), v.end(), -cur);
			ans += hi - lo;
		}
	}
	
	cout << ans;
}