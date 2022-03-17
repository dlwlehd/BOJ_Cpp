#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    ll res = 0;
    int idx = 1;
    for (int i = 0; i < n; i++) {
        res += abs(idx - a[i]);
        idx++;
    }
    cout << res;
}