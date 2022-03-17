#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    if (n == 0) {
        cout << 0;
        return 0;
    }
    for (int &i: v) cin >> i;
    int cnt = 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + v[i] > m) {
            cnt++;
            sum = v[i];
        } else sum += v[i];
    }

    cout << cnt;
}