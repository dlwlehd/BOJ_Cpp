#include <bits/stdc++.h>
using namespace std;

int n;
string s[1001];

bool cmp(string a, string b) {
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else {
		int a_sum = 0, b_sum = 0;
		for (int idx = 0; idx < a.length(); idx++) {
			if ('0' <= a[idx] && a[idx] <= '9')    a_sum += a[idx] - '0';
			if ('0' <= b[idx] && b[idx] <= '9')    b_sum += b[idx] - '0';
		}
		if (a_sum < b_sum) return 1;
		else if (a_sum > b_sum) return 0;
		else {
			return a < b;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i] << "\n";
	}
}