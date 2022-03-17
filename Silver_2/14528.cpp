#include <bits/stdc++.h>

using namespace std;

int n, m;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> m;
    set<tuple<int, int, int>> s;
    vector<string> a(n), b(n);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    int res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                s.clear();
                bool flag = 0;
                for (int x = 0; x < n; x++) s.insert({a[x][i], a[x][j], a[x][k]});
                for (int x = 0; x < n; x++) {
                    if (s.count({b[x][i], b[x][j], b[x][k]})) flag = 1;
                }
                if (!flag) res++;
            }
        }
    }
    cout << res;
}