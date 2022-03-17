#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        int mx = 0;
        ll res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > mx) mx = a[i];
            else res += mx - a[i];
        }
        cout << res << "\n";
    }
}