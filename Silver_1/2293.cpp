#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[10002];
int a[102];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {
    
    input();
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - a[i] >= 0)
                d[j] += d[j - a[i]];
        }
    }
    cout << d[k];
}
