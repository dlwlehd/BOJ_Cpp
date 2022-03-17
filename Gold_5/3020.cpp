#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n, h;
    cin >> n >> h;
    vector<int> b(n / 2), t(n / 2);
    for (int i = 0; i < n / 2; i++) {
        cin >> b[i] >> t[i];
    }
    sort(all(b));
    sort(all(t));
    int res = 987654321;
    int cnt = 1;
    for (int i = 1; i <= h; i++) {
        int x = b.size() - (lower_bound(all(b), i) - b.begin());
        x += t.size() - (upper_bound(all(t), h - i) - t.begin());
        if (res == x) cnt++;
        else if (res > x) {
            res = x;
            cnt = 1;
        }
    }
    cout << res << " " << cnt;
}