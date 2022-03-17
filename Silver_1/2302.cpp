#include <bits/stdc++.h>
using namespace std;

int n, m, tot = 1;
int d[1000002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {
    
    input();
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    d[1] = 0;
    d[2] = 2;
    d[3] = 3;

    for (int i = 4; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }

    vector<int> tmp;
    if (m == 0) cout << d[n];

    else {
        tmp.push_back(a[0] - 1);

        for (int i = 1; i < m; i++) {
            tmp.push_back(a[i] - a[i - 1] - 1);
        }

        tmp.push_back(n - a[m - 1]);

        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] <= 1) continue;
            tot *= d[tmp[i]];
        }
        cout << tot;
    }
}
