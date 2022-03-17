#include <bits/stdc++.h>
using namespace std;

int n, k;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    cout << a[k - 1];
}