#include <bits/stdc++.h>
using namespace std;

int n, m;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main(void) {

	input();
    
    while(cin >> n >> m) {
        int ans = 0;
        for (int i = n; i <= m; i++) {
            string s = to_string(i);
            vector<int> count(10);
            bool check = false;

            for (int j = 0; j < s.size(); j++) {
                count[s[j] - '0']++;
                if (count[s[j] - '0'] > 1) {
                    check = true;
                    break;
                }
            }
            if (check)
                continue;
            ans++;
        }
        cout << ans << "\n";
    }
}