#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<char> s(18);
int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	sort(s.begin(), s.begin() + n);

	vector<int> v(m, 1);

	for (int i = 0; i < n - m; i++)
		v.push_back(0);

	do {
		string res = "";
		for (int i = 0; i < v.size(); i++)
			if (v[i] == 1) res += s[i];

		int cnt1 = 0;
		int cnt2 = 0;

		for (int i = 0; i < res.size(); i++) {
			if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u')
				cnt1++;
			else
				cnt2++;
		}

		if (cnt1 < 1 || cnt2 < 2) 
			continue;

		cout << res << "\n";

	} while (prev_permutation(v.begin(), v.end()));

}