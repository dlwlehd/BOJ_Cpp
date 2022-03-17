#include <bits/stdc++.h>
using namespace std;

int dp[21][21][21] = {0};

int func(int a, int b, int c) {
	
	if (a <= 0 || b <= 0 || c <= 0) return dp[0][0][0];

	if (a > 20 || b > 20 || c > 20) return func(20,20,20);
		
	if (dp[a][b][c] != 0) return dp[a][b][c];
	
	if (a < b && b < c) {
		dp[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c-1) - func(a, b - 1, c);
		return dp[a][b][c];
	}
	
	dp[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
    dp[0][0][0] = 1;
	while(true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << "\n";
	}
}