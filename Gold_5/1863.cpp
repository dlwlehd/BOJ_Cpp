#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
typedef long long ll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n, ans = 0;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (auto &i: a) cin >> i.X >> i.Y;
    sort(all(a));
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() > a[i].Y) s.pop();
        if (a[i].Y && (s.empty() || s.top() < a[i].Y)) {
            s.push(a[i].Y);
            ans++;
        }
    }
    cout << ans;
}