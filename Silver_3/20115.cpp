#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<double> v(n);
    for (auto &i: v) cin >> i;
    sort(v.rbegin(), v.rend());
    double t = v[0];
    for (int i = 1; i < n; i++) {
        t += v[i] / 2;
    }
    cout << t;
}