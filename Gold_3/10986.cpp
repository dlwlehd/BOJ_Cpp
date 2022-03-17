#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll pSum[1000002] = {0};
ll res = 0;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n >> m;
    vector<ll> cnt(m, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pSum[i] = (pSum[i - 1] + x) % m;
        if (!pSum[i]) res++;
        cnt[pSum[i]]++;
    }

    for (int i = 0; i < m; i++) {
        res += cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << res;
}