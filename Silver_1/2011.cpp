#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;

const int mod = 1000000;
ll dp[5002] = {0};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    string x;
    cin >> x;
    int a[5002];
    for (int i = 1; i <= x.size(); i++) a[i] = x[i - 1] - '0';
    if (x.size() == 1 && x[0] == '0') {
        cout << 0;
        return 0;
    }
    dp[0] = 1;

    for (int i = 1; i <= x.size(); i++) {
        if (a[i] >= 1 && a[i] <= 9) dp[i] = (dp[i - 1] + dp[i]) % mod;
        if (i == 1) continue;
        int t = a[i] + a[i - 1] * 10;
        if (t >= 10 && t <= 26) dp[i] = (dp[i - 2] + dp[i]) % mod;
    }
    cout << dp[x.size()];
}