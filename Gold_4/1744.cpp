#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;

int n;
bool vis[52] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = n - 1; i > 0; i--) {
        if (vis[i] || vis[i - 1]) continue;
        if (a[i] > 1 && a[i - 1] > 1) {
            res += a[i] * a[i - 1];
            vis[i] = vis[i - 1] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (vis[i] || vis[i + 1]) continue;
        if (a[i] < 0 && a[i + 1] < 0) {
            res += a[i] * a[i + 1];
            vis[i] = vis[i + 1] = 1;
        }
    }
    int z = 0;
    for (int i = 0; i < n; i++) if (a[i] == 0) z++;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (z > 0 && a[i] < 0) z--;
            else res += a[i];
        }
    }

    cout << res;
}
