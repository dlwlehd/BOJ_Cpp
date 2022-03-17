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
    int f = 0, s = 1, res = 1;
    for (int i = 1; i < abs(n); i++) {
        res = (f + s) % 1000000007;
        f = s;
        s = res;
    }
    if (n == 0) cout << 0;
    else cout << res;
}
