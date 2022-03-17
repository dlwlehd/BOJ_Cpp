#include <bits/stdc++.h>
using namespace std;

int n, sum = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * (sum - a[i]);
        sum -= a[i];
    }
    cout << res;
}