#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		string a;
		getline(cin, a);
		if (a == ".") break;
		stack<char> s;
		bool check = true;
		for (auto c : a) {
			if (c == '(' || c == '[') s.push(c);
			else if (c == ')') {
				if (s.empty() || s.top() != '(') {
					check = false;
					break;
				}
				s.pop();
			}
			else if (c == ']') {
				if (s.empty() || s.top() != '[') {
					check = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) check = false;
		
		if (check) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}
