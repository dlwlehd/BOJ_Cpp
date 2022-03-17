#include <bits/stdc++.h>
using namespace std;

int n, m;
long long res = 987654321;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> m;
    vector<int> a(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    
    long long left = mx;
    long long right = 1000000000;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (mid < mx) break;
        int cnt = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > mid) {
                cnt++;
                sum = 0;
                i--;
            }
            if (i == n - 1) cnt++;
        }
        
        if (cnt <= m) {
            res = min(res, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << res;
}