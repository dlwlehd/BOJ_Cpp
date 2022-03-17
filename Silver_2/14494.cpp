#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];
const int mod = 1e9 + 7;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) fill(d[i], d[i] + m, 0);
    d[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % mod;
            d[i][j] += d[i - 1][j - 1];
            d[i][j] %= mod;
        }
    }
    cout << d[n][m];
}