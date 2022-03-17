#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main() {
    input();
    int n;
    ll res = 0;
    cin >> n;
    vector<int> a(n), vis(n, 0);
    for (int &i: a) cin >> i;

    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && !vis[a[en]]) {
            vis[a[en]] = 1;
            en++;
        }
        res += en - st;
        vis[a[st]] = 0;
    }
    cout << res;
}