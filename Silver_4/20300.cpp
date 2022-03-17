#include <bits/stdc++.h>
using namespace std;

long long n, ans;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n;
    vector<long long> ex(n);
    for (int i = 0; i < n; i++) {
        cin >> ex[i];
    }
    sort(ex.begin(), ex.end());

    if (n % 2) {
        ans = ex[n - 1];
        for (int i = 0; i < (n - 1) / 2; i++)
            ans = max(ans, ex[i] + ex[n - 2 - i]);
    }
    else {
        ans = ex[0] + ex[n - 1];
        for (int i = 1; i < n / 2; i++)
            ans = max(ans, ex[i] + ex[n - 1 - i]);
    }
    
    cout << ans;
}