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
        sort(a.rbegin(), a.rend());
        deque<int> d;
        d.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) d.push_front(a[i]);
            else d.push_back(a[i]);
        }
        
        int res = abs(d[n - 1] - d[0]);
        for (int i = 0; i < n - 1; i++) {
            res = max(res, abs(d[i] - d[i + 1]));
        }
        cout << res << "\n";
    }
}