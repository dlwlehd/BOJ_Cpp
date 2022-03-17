#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
typedef long long ll;

const int INF = 1e9 + 9;
int n, t;
ll a[50002], psum[50002] = {0}, dp[4][50002] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    cin >> t;

    for (int i = 1; i <= 3; i++) {
        for (int j = i * t; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - t] + (psum[j] - psum[j - t]));
        }
    }
    cout << dp[3][n];
}