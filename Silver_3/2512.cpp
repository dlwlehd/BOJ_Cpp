#include <bits/stdc++.h>
using namespace std;

int n, m, res = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
    cin >> n;
}

int main() {
    input();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    
    sort(a.begin(), a.end());
    int left = 0;
    int right = a[n - 1];
    while (left <= right) {
        int mid = (left + right) / 2;
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            if (mid < a[i]) tot += mid;
            else tot += a[i];
        }
        
        if (tot <= m) {
            left = mid + 1;
            res = mid;
        }
        else {
            right = mid - 1;
        }
    }
    cout << res;
}