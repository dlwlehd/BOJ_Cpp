#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int D(int n) { 
	return n * 2 % 10000; 
}

int S(int n) { 
	return (n + 9999) % 10000;
}

int L(int n) {
	return n * 10 % 10000 + n / 1000; 
}

int R(int n) {
	return n * 1000 % 10000 + n / 10; 
}

int main() {
    input();
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int prev[10002];
		fill(prev, prev + 10000, -1);
		prev[a] = a;
		char op[10002];
		fill(op, op + 10000, -1);
		
		queue<int> q;
		q.push(a);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					int next = D(cur);
					if (prev[next] == -1) {
						prev[next] = cur;
						op[next] = 'D';
						q.push(next);
					}
				} else if (i == 1) {
					int next = S(cur);
					if (prev[next] == -1) {
						prev[next] = cur;
						op[next] = 'S';
						q.push(next);
					}
				} else if (i == 2) {
					int next = L(cur);
					if (prev[next] == -1) {
						prev[next] = cur;
						op[next] = 'L';
						q.push(next);
					}
				} else {
					int next = R(cur);
					if (prev[next] == -1) {
						prev[next] = cur;
						op[next] = 'R';
						q.push(next);
					}
				}
			}
		}
		
		stack<char> s;
		int cur = b;
		while(prev[cur] != cur){
			s.push(op[cur]);
			cur = prev[cur];
		}
		
		while(!s.empty()){
			cout << s.top();
			s.pop();
		}
		
		cout << "\n";
	}
}