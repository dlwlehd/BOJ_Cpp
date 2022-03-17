#include <bits/stdc++.h>

using namespace std;
int n;
int cnt = 0;
vector<int> a;
vector<int> res;
vector<pair<int, int>> sb;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back(x);
		sb.push_back({ y,z });
	}

	for (int i = 123; i < 988; i++) {

		string s = to_string(i);
		if (s[0] == '0' || s[1] == '0' || s[2] == '0') continue;
		if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) continue;
		bool check = true;

		for (int j = 0; j < n; j++) {
			string temp = to_string(a[j]);
			int strike = 0;
			int ball = 0;

			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (temp[k] == s[l] && k == l) strike++;
					if (temp[k] == s[l] && k != l) ball++;
				}
			}
			
			if (!(strike == sb[j].first && ball == sb[j].second)) check = false;
		}
		
		
		if (check) cnt++;
	}
	
	cout << cnt;
}