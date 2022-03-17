#include <bits/stdc++.h>
using namespace std;

int n, w;
int chart[16];
long long res;

void func(int k, long long coin, long long money) {
	if (k == n + 1) {
		res = max(res, money);
		return;
	}
	else {
		for (int i = k; i <= n; i++) {
			long long temp = money / chart[i];

			func(i + 1, coin + temp, money - temp * chart[i]);
			func(i + 1, 0, money + coin * chart[i]);
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> chart[i];
	}

	func(1, 0, w);
	cout << res;
}