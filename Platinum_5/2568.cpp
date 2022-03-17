#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;
bool check[500001];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n; cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].X >> v[i].Y;
    sort(v.begin(), v.end(), [](pii a, pii b) { return a.X < b.X; });
    vector<int> LIS, pos(n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || LIS.back() < v[i].Y) {
            LIS.push_back(v[i].Y);
            pos[i] = LIS.size();
            continue;
        }
        int idx = lower_bound(LIS.begin(), LIS.end(), v[i].Y) - LIS.begin();
        LIS[idx] = v[i].Y;
        pos[i] = idx + 1;
    }

    int temp = LIS.size();
    for (int i = n; i --> 0;) {
        if (pos[i] == temp) {
            check[v[i].Y] = true;
            temp--;
        }
    }

    cout << n - LIS.size() << '\n';
    for (int i = 0; i < n; i++) if (check[v[i].Y] == false) {
            cout << v[i].X << '\n';
        }
}
