#include <bits/stdc++.h>
using namespace std;

int n, k;
long long cnt = 0;
queue<int> q[21];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		int len = input.length();

		while (!q[len].empty() && i - q[len].front() > k) {
			q[len].pop();
		}
		cnt += q[len].size();
		q[len].push(i);
	}

	cout << cnt;
}
