#include <bits/stdc++.h>
using namespace std;

int n;
int d[1002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main() {

    input();
	cin >> n;
	
	d[1] = 1;
	d[2] = 0;
	d[3] = 1;
	d[4] = 1;

	for (int i = 5; i <= n; ++i) {
		if (min({ d[i - 1], d[i - 3], d[i - 4] }) == 1) {
			d[i] = 0;
		}
		else {
			d[i] = 1;
		}
	}

	if (d[n]) cout << "SK";
	else cout << "CY";

}