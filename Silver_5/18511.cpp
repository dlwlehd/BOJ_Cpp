#include <bits/stdc++.h>
using namespace std;

int n, k, len;
vector<int> a;
int mx = -1;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

void func(int idx, int tot) {
	
	if (idx == len + 1) return;

	if (n >= tot && mx < tot) {
		mx = tot;
	}

	for (int i = 0; i < k; i++) {
		func(idx + 1, tot + pow(10, idx) * a[i]);
	}
}

int main(void) {

	input();
	cin >> n >> k;

	int t = n;
	while (t > 0) {
		t /= 10;
		len++;
	}

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	func(0, 0);
	cout << mx;
}