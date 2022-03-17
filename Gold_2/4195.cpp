#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define x first
#define y second

int Parent[200002], s[200002];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int Find(int x) {
    return x == Parent[x] ? x : Parent[x] = Find(Parent[x]);
}

int Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return s[a];
    if (a > b) swap(a, b);
    Parent[b] = a;
    s[a] += s[b];
    return s[a];
}

int main() {
    input();
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 1;
        cin >> n;
        unordered_map<string, int> M;
        for (int i = 0; i <= n + 1; i++) {
            Parent[i] = i;
            s[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            string a, b;
            cin >> a >> b;
            if (M.count(a) == 0) M[a] = cnt++;
            if (M.count(b) == 0) M[b] = cnt++;
            cout << Union(M[a], M[b]) << '\n';
        }
    }
}