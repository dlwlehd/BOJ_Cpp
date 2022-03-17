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
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end(), greater<>());
    int d = 0;
    for (int i = 0; i < n; i++) {
        d = max(d, a[i] + i + 1);
    }
    cout << d + 1;
}