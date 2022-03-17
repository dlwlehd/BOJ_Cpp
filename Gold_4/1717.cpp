#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define x first
#define y second

int n, m, Parent[1000001];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "w", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "r", stdout);
}

int Find(int x) {
    return Parent[x] == x ? x : Parent[x] = Find(Parent[x]);
}

void Union(int a, int b) {
    a < b ? Parent[b] = a : Parent[a] = b;
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i <= n; i++) Parent[i] = i;
    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        a = Find(a);
        b = Find(b);
        if (op) cout << (a == b ? "YES\n" : "NO\n");
        else Union(a, b);
    }
}