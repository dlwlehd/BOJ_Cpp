#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	cin >> a;
	int count = 0;
	stack<char> s;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(') s.push('(');
		else if (a[i] == ')') {
			if (a[i-1] == '(') {
				s.pop();
				count += s.size();
			}
			else {
				count++;
				s.pop();
			}
		}
	}

	cout << count;
}
