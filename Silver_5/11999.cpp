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
    cin >> x >> y >> m;
    int d[1002] = {0};
    d[0] = 1;
    d[x] = 1;
    d[y] = 1;
    for (int i = 1; i <= m; i++) {
        if (i - x >= 0 && d[i - x]) d[i] = 1;
        if (i - y >= 0 && d[i - y]) d[i] = 1;
    }
    for (int i = m; i >= 0; i--) {
        if (d[i]) {
            cout << i;
            return 0;
        }
    }
}