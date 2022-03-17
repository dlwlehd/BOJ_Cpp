#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& i: v) cin >> i;
	
	int s = 0, e = n - 1;
	int ans = v[s] + v[e];
	while (true) {
		if (v[s] + v[e] > 0) e--;
        else s++;
		
		if (s >= e) break;
		
        if (abs(v[s] + v[e]) < abs(ans)){
            ans = v[s] + v[e];
        }
	}
	
	cout << ans;
}