#include <bits/stdc++.h>
using namespace std;

int n, k;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> k;

    int max_sum = k * (k + 1) / 2;
    n -= max_sum;

    if (n < 0) {
        cout << -1;
    }
    else {
        if (n % k == 0) cout << k - 1;
        else cout << k;
    }
}