#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 9;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int t;
    cin >> t;
	int idx = 1;
    while (t--) {
        int n, k;
		cin >> n >> k;
		vector<int> a(n), lis;
		for (int &i: a) cin >> i;
		for (int i = 0; i < n; i++) {
			if (i == 0 || lis.back() < a[i]) lis.push_back(a[i]);
			else *lower_bound(lis.begin(), lis.end(), a[i]) = a[i];
		}
		cout << "Case #" << idx << "\n";
		if (k > lis.size()) cout << "0\n";
		else cout << "1\n";
		idx++;
    }
}