#include <bits/stdc++.h>
using namespace std;

int sub;
int cnt;
int result = 0;
string s1;
string s2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

	cin >> s1 >> s2;
	sub = s2.length() - s1.length();

	for (int i = 0; i <= sub; i++) {
		cnt = 0;
		for (int j = 0; j < s1.length(); j++) {
			if (s1[j] == s2[j + i]) {
				cnt++;
			}
		}
		result = max(result, cnt);
	}
	result += sub;
	result = s2.length() - result;

	cout << result;
}