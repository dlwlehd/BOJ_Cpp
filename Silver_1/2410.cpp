#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

int n, dp[1000001][21];
const int mod = 1000000000;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int func(int remain, int limit){
	if (remain == 0) return 1;
	if (limit == 0) return 1;
	int &ret = dp[remain][limit];
	if (ret != -1) return ret;
    
	ret = func(remain, limit-1);
	if (remain - (1 << limit) >= 0) ret = (ret + func(remain - (1 << limit), limit)) % mod;
	return ret;
}

int main(){
    input();
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << func(n, 20);
}