#include <bits/stdc++.h>
using namespace std;

int n, k;
int mx = -1;
int dp[102][100002];
int weight[102], val[102];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> val[i];
	}
	
	for(int i = 0;i< n;i++){
		for(int j = 0;j<=k;j++){
			if(j >= weight[i]){
				dp[i+1][j] = max(dp[i][j], dp[i][j-weight[i]] + val[i]);
			}
			else{
				dp[i+1][j] = dp[i][j];
			}
			mx = max(dp[i+1][j], mx);
		}
	}
	
	cout << mx;
}
