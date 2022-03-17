#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[1000002];
int m = 15746;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {
    
    input();
    cin >> n;

    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
        d[i] %= m;
    }

    cout << d[n];
}
