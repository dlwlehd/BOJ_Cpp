#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define x first
#define y second

int n, m, k, Parent[10002], A[10002];
bool vis[10002];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int Find(int x) {
    return Parent[x] == x ? x : Parent[x] = Find(Parent[x]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    Parent[b] = a;
    A[a] = min(A[a], A[b]);
}

int main() {
    input();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) Parent[i] = i;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[Find(i)]) {
            vis[Find(i)] = 1;
            tot += A[Find(i)];
        }
    }
    if (tot > k) cout << "Oh no";
    else cout << tot;
}