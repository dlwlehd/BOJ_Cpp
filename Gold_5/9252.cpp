#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

int dp[1001][1001];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    string a, b; cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
		    if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
		    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
	}
	string ans;
	int x = a.size(), y = b.size();
	while (x != 0 && y != 0) {
		int cur = dp[x][y];
		if (dp[x - 1][y - 1] == cur) { 
            x--;
            y--; 
        }
		else if (dp[x - 1][y] == cur) x--;
		else if (dp[x][y - 1] == cur) y--;
		else {
            ans += a[x - 1]; 
            x--;
            y--; 
        }
	}
	reverse(ans.begin(), ans.end());
	cout << dp[a.size()][b.size()] << '\n' << ans << '\n';
}
