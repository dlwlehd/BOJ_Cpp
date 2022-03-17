#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool cmp1(string a, string b) {
	return a + b > b + a;
}

bool cmp2(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main() {
	input();
	int n, k;
	cin >> k >> n;
	vector<string> a(k);
	for (int i = 0; i < k; i++) cin >> a[i];
	sort(a.begin(), a.end(), cmp2);
	
	string res = "";
	string mx = a[k - 1];
	for (int i = 0; i < n - k; i++) {
		a.push_back(mx);
	}
	sort(a.begin(), a.end(), cmp1);
	for (int i = 0; i < a.size(); i++) {
		res += a[i];
	}
	cout << res;
}
