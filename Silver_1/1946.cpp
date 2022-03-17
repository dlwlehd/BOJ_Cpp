#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int,int> pi;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pi> a(n);
        for (auto &i: a) cin >> i.x >> i.y;
        sort(a.begin(), a.end());
        int res = 1;
        int mn_y = a[0].y;
        for (int i = 1; i < n; i++) {
            if (a[i].y < mn_y) {
                mn_y = a[i].y;
                res++;
            }
        }
        cout << res << "\n";
    }
}