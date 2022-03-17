#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main() {
    input();

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (prev_permutation(a.begin(), a.end())) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
    }

    else cout << -1;
}