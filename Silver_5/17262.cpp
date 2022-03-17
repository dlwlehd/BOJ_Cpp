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
    int mx = -1, mn = 987654321;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mx = max(a, mx);
        mn = min(b, mn);
    }
    int x = mx - mn;
    cout << (x < 0 ? 0 : x);
}