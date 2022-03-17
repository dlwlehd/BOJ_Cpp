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
    vector<int> a(n), b(n);
    vector<bool> vis(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = 0;
    for (int i = 0; i < n / 2 + 1; i++) {
        if (a[i] >= b[i + n / 2]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}