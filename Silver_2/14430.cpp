#include <bits/stdc++.h>
using namespace std;

int a[1005][1005], d[1005][1005];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n; i++) fill(d[i], d[i] + m, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) d[i][j] = 1;
            d[i][j] += max(d[i - 1][j], d[i][j - 1]);
        }
    }
    cout << d[n][m];
}