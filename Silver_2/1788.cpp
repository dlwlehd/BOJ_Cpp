#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[1000001];

void fibo() {
	a[0] = 0;
	a[1] = 1;
	for (int num = 2; num <= n; num++) {
		a[num] = (a[num - 1] + a[num - 2]) % 1000000000;
	}
}

int main() {

	cin >> n;
	if (n == -1) {
		cout << 1 << '\n' << 1 << '\n';
		return 0;
	}
	else if (n < -1) {
		n *= -1;
		fibo();
		if (n % 2 == 0) {
			cout << -1 << '\n' << a[n];
		}
		else {
			cout << 1 << '\n' << a[n];
		}
	}
	else {
		fibo();
		if (a[n] > 0) { 
			cout << 1 << '\n' << a[n]; 
		}
		else {
			cout << 0 << '\n' << 0 << '\n';
		}
	}

}