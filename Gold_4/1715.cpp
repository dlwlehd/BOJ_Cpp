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
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-1 * x);
	}
	
	bool flag = false;
	int t1 = 0, t2 = 0;
	
	int res = 0;
	while (!pq.empty()) {
		if (!flag) {
			t1 = -1 * pq.top();
			pq.pop();
			flag = true;
		} else {
			t2 = -1 * pq.top();
			pq.pop();
			flag = false;
			
			t2 += t1;
			res += t2;
			
			pq.push(-1 * t2);
		}
	}
	cout << res;
}
