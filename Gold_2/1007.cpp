#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cout << fixed << setprecision(8);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pi> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].X >> v[i].Y;
        vector<int> a(n);
        fill(a.begin() + n / 2, a.end(), 1);
        double ans = 1e9;
        do {
            double x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                if (a[i]) x += v[i].X, y += v[i].Y;
                else x -= v[i].X, y -= v[i].Y;
            }
            ans = min(ans, hypot(x, y));
        } while (next_permutation(a.begin(), a.end()));
        cout << ans << '\n';
    }
}
