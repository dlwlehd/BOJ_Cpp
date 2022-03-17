#include <bits/stdc++.h>
using namespace std;

int n;
int a[502];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n;
    fill(a, a + 502, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cin >> a[x];
    }
    vector<int> arr, v;
    for (int i = 0; i < 502; i++) {
        if (a[i] != 0) {
            arr.push_back(a[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        int u = arr[i];
        int llo = lower_bound(v.begin(), v.end(), u) - v.begin();
        if (llo == v.size()) {
            v.push_back(u);
        }
        else {
            v[llo] = u;
        }
    }
    cout << n - v.size();
}