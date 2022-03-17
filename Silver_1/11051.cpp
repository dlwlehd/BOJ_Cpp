#include <bits/stdc++.h>
using namespace std;

int comb[1002][1002];
int mod = 10007;
int n, m;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {
    input();

    for (int i = 1; i <= 1000; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }

    cin >> n >> m;
    cout << comb[n][m];
}