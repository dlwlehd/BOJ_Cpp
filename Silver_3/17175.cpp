#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n;
    cin >> n;
    int d[52];
    d[0] = d[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = (d[i - 1] + d[i - 2] + 1) % 1000000007;
    }
    cout << d[n];
}
