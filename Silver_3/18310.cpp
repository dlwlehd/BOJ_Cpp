#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    n = (n - 1) / 2;
    cout << a[n];
}