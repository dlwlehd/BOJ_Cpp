#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll pSum[50002] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        pSum[i + 1] = a[i] + pSum[i];
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= n - i; j++) {
            int start = j;
            int end = j + i;
            ll sum = pSum[end] - pSum[start];
            if (sum % 7 == 0) {
                cout << i;
                return 0;
            }
        }
    }

    cout << 0;
}