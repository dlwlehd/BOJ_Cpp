#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int d[1002];
    fill(d, d + n, INF);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            if (i + j > n) continue;
            d[i + j] = min(d[i + j] , d[i] + 1);
        }
    }

    cout << (d[n - 1] == INF ? -1 : d[n - 1]);
}