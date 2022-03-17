#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int res = 0;
    for (int i = 0; i < n; i++) {
        vector<int> lis{a[i]}, lds{-a[i]};
        for (int j = i + 1; j < n; j++) {
            if (lis.empty() || lis.back() < a[j]) lis.push_back(a[j]);
            else if (a[i] < a[j]) *lower_bound(lis.begin(), lis.end(), a[j]) = a[j];
        }
        for (int j = i + 1; j < n; j++) {
            if (lds.empty() || lds.back() < -a[j]) lds.push_back(-a[j]);
            else if (a[j] < a[i]) *lower_bound(lds.begin(), lds.end(), -a[j]) = -a[j];
        }
        res = max<int>(res, lis.size() + lds.size() - 1);
    }

    cout << res;
}