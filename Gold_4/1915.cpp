#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

int board[1002][1002], dp[1002][1002] = {0}, res = -1; 

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            board[i][j] = x - '0';
        }
    }
    
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) dp[i][j] = board[i][j];
			else if (board[i][j] == 1) dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			
			res = max(res, dp[i][j]);
		}
	}

    cout << res * res;
}