#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
typedef long long ll;

const int INF = 1e9 + 9;
int n, m, t;
ll cnt = 0, a[1002], b[1002];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> t >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        ll s = a[i];
        x.push_back(s);
        for (int j = i + 1; j < n; j++) {
            s += a[j];
            x.push_back(s);
        }
    }
    for (int i = 0; i < m; i++) {
        ll s = b[i];
        y.push_back(s);
        for (int j = i + 1; j < m; j++) {
            s += b[j];
            y.push_back(s);
        }
    }
    sort(all(x));
    sort(all(y));
    for (int i = 0; i < x.size(); i++) {
        cnt += (upper_bound(all(y), t - x[i]) - y.begin()) - (lower_bound(all(y), t - x[i]) - y.begin());
    }
    cout << cnt;
}