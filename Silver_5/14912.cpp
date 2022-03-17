#include <bits/stdc++.h>
using namespace std;

int n, d;
int res = 0;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int func(int idx, int n) {
    int cnt = 0;
    while(n > 0) {
        if (n % 10 == idx) cnt++;
        n /= 10;
    }
    return cnt;
}

int main(void) {

	input();
    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        res += func(d,i);
    }
    cout << res;
}