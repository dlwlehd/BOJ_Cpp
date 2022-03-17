#include <bits/stdc++.h>
using namespace std;

int n;
int mx = -1;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n;
	map<string, int> M;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		M[s]++;
	}
	string ans; 
	for (const auto& [s, cnt] : M) {
		if (mx < cnt || mx == cnt && ans > s)
			mx = cnt, ans = s;
	}
	cout << ans << "\n";
}