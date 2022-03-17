#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define x first
#define y second

int n, m, Parent[1000001];

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
    a = Find(a);
    b = Find(b);
    a < b ? Parent[b] = a : Parent[a] = b;
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) Parent[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x) Union(i, j);
        }
    }
    vector<int> a(m);
    for (int &i: a) cin >> i;
    for (int i = 1; i < m; i++) {
        int x, y;
        x = Find(a[i - 1]);
        y = Find(a[i]);
        if (x != y) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}