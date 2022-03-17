#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool valid(string a) {
	stack<char> t;
	bool check = true;
	for (auto c : a) {
		if (c == '(' || c == '[') t.push(c);
		else if (c == ')') {
			if (t.empty() || t.top() != '(') {
				check = false;
				break;
			}
			t.pop();
		}
		else if (c == ']') {
			if (t.empty() || t.top() != '[') {
				check = false;
				break;
			}
			t.pop();
		}
	}
	if (!t.empty()) check = false;

	return check;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	cin >> a;
	stack<char> s;
	long long result = 0;
	int temp = 1;

	if (!valid(a)) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(') { 
			s.push(a[i]); 
			temp *= 2;
		}
		else if (a[i] == '[') {
			s.push(a[i]);
			temp *= 3;
		}

		else if (a[i] == ')') {
			if (a[i-1] == '(') {
				result += temp;
			}
			s.pop();
			temp /= 2;
		} else if (a[i] == ']') {
			if (a[i - 1] == '[') {
				result += temp;
			}
			s.pop();
			temp /= 3;
		}
	}

	cout << result;
}
