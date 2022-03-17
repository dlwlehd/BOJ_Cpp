#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int main() {
    input();
    cin >> n;
    int a[102][102] = {0};
    ll d[102][102] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = a[i][j];
            if (x == 0) continue;
            if (!oob(i + x, j)) d[i + x][j] += d[i][j];
            if (!oob(i, j + x)) d[i][j + x] += d[i][j];
        }
    }
    n--;
    cout << d[n][n];
}