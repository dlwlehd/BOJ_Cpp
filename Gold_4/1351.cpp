#include <bits/stdc++.h>

using namespace std;

map<long long, long long> dp;
long long n;
int p, q;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

long long func(long long n){
	auto finder = dp.find(n);
	if(finder != dp.end()) return finder->second;
	return dp[n] = func(n / p) + func(n / q);
}

int main() {
    input();
	long long n;
	cin >> n >> p >> q;
	dp[0] = 1;
	
	cout << func(n);
}