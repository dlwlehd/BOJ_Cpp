#include <bits/stdc++.h>
using namespace std;

string s;
bool flag = false;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

void JavaToC() {
	while (s.find('_') != string::npos) {
		int pos = s.find('_');
		s.erase(pos, 1);
		s[pos] -= ('a' - 'A');
	}
}

void CToJava() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < 'a') {
			s.insert(i, "_");
			s[i + 1] += ('a' - 'A');
			i++;
		}
	}
}

int main() {
	input();

	cin >> s;

	if (s[0] < 'a' || s[0] == '_' || s[s.size() - 1] == '_') flag = 1;

	if (!flag) {
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == '_' && s[i + 1] == '_') {
				flag = true;
				break;
			}
		}
	}

	if (s.find('_') != string::npos) {
		for (int i = 0; i < s.size(); i++) {
			if ('A' <= s[i] && s[i] <= 'Z') {
				flag = true;
				break;
			}
		}
		JavaToC();
	}
	else CToJava();

	if (flag) cout << "Error!";
	else cout << s;
}
