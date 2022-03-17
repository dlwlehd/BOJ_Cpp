#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a, b, c;

ll calc(ll a, ll b, ll c) {
	if (b == 1) return a % c;

	ll val = calc(a, b / 2, c);
	val = val * val % c;

	if (b % 2 == 0) return val;

	return val * a % c;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;

	cout << calc(a, b, c);
}