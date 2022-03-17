#include <bits/stdc++.h>

using namespace std;

int n, s, a[40], t, sum;
long long res;
map<int, int> cnt;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void dfs1(int pos) {
    if (pos == t) {
        auto iter = cnt.find(sum);
        if (iter != cnt.end()) ++iter->second;
        else cnt[sum] = 1;
        return;
    }
    dfs1(pos + 1);
    sum += a[pos];
    dfs1(pos + 1);
    sum -= a[pos];
}

void dfs2(int pos) {
    if (pos == n) {
        auto iter = cnt.find(s - sum);
        if (iter != cnt.end()) res += iter->second;
        return;
    }
    dfs2(pos + 1);
    sum += a[pos];
    dfs2(pos + 1);
    sum -= a[pos];
}

int main() {
    input();
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    t = n / 2;
    dfs1(0);
    dfs2(t);
    if (s == 0) res--;
    cout << res;
}