#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n), lis;
    for (int& i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        if (i == 0 || lis.back() < a[i]) lis.push_back(a[i]);
        else *lower_bound(lis.begin(), lis.end(), a[i]) = a[i];
    }
    cout << lis.size();
}