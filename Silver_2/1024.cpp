#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int s (int n) {
    return n * (n - 1) / 2;
}

int main() {
    input();
    int n, l;
    cin >> n >> l;
    int idx = l;
    int p = l;
    int res;

    while (true) {
        int ncount = idx;
        int sum = s(p);
        if ((n - sum) % ncount == 0) {
            res = (n - sum) / ncount;
            break;
        }
        idx++;
        p++;
    }

    if (p > 100 || res < 0) {
        cout << -1;
        return 0;
    }
    idx = 0;
    for (int i = 0; i < p; i++) {
        cout << res + idx << " ";
        idx++;
    }
}