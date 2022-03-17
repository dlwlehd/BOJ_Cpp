#include <bits/stdc++.h>
using namespace std;

int n, m;
int res = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
    cin >> n >> m;
}

int main() {
    input();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int left = 0;
    int right = a[n - 1];
    while (left <= right) {
        long long tot = 0;
        int mid = (left + right) / 2;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) tot += a[i] - mid;
        }
        if (tot < m) {
            right = mid - 1;
        }
        else {
            res = mid;
            left = mid + 1;
        }
    }
    cout << res;
}