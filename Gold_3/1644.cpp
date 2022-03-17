#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    bool sieve[4000001] = {};
	for (int i = 2; i <= 4000000; i++) sieve[i] = true;
	for (int i = 2; i <= 2000; i++) {
		if (sieve[i]) {
			for (int p = i * i; p <= 4000000; p += i) sieve[p] = false;
		}
	}
	int n; 
    cin >> n; 
    int ans = 0;
	if (n == 1) cout << 0 << '\n';
	else {
		vector<int> prime;
		for (int i = 2; i <= n; i++) {
			if (sieve[i]) prime.push_back(i);
		}
		auto start = prime.begin(), end = prime.begin();
		int sum = prime[0];
		while (true) {
			if (sum > n) sum -= *(start++);
			else if (sum <= n) {
				if (sum == n) ans++;
				if (end + 1 == prime.end()) break;
				sum += *(++end);
			}
		}
		cout << ans << '\n';
	}
}
