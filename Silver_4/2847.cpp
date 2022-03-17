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
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int res = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1]) {
            res += a[i] - a[i + 1] + 1;
            a[i] = a[i + 1] - 1;
        }
    }
    cout << res;
}