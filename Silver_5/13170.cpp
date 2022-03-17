#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, k, p, w;
    cin >> n >> k >> p >> w;
    if (p % w == 0) cout << p / w;
    else cout << p / w + 1;
}