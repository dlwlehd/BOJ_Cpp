#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[100002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {
    
    input();
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<pair<int, int>> b(m);

    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cout << d[y] - d[x - 1] << "\n";
    }
}
