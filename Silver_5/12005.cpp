#include <bits/stdc++.h>

using namespace std;

int x, y, m;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());

    int res = -1;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] - a[i] > k) break;
            cnt++;
        }
        res = max(res, cnt);
    }
    cout << res;
}