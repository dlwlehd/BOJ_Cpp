#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int n;
    cin >> n;
    int d[150], dp[300010];
    for (int i = 2; i < 145; i++) {
        d[i - 1] = (i * i * i - i) / 6;
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x = 987654321;
        for (int j = 1; d[j] <= i; j++) {
            int t = i - d[j];
            if (dp[t] < x) x = dp[t];
        }
        dp[i] = x + 1;
    }
    cout << dp[n];
}