#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	vector<string> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		reverse(v[i].begin(), v[i].end());
		ans.push_back(stoll(v[i]));
	}

	sort(ans.begin(),ans.end());
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}