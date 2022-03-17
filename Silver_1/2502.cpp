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
    int a[32];
    int d, k;
    cin >> d >> k;
    a[0] = a[1] = 1;
    for (int i = 2; i < 32; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    int aidx = d - 3;
    int bidx = d - 2;

    for (int i = 1; i <= 33334; i++) {
        if ((k - a[aidx] * i) % a[bidx] == 0) {
            cout << i << "\n";
            cout << (k - a[aidx] * i) / a[bidx];
            return 0;
        }
    }
}