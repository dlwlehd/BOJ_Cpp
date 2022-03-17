#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
vector<int> x, y;
set<int> a, b;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        x.push_back(t);
        a.insert(t);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        y.push_back(t);
        b.insert(t);
    }
    
    for (int i = 0; i < m; i++) {
        if (!a.count(y[i])) cnt++;
    }
    for (int i = 0; i < n; i++) {
        if (!b.count(x[i])) cnt++;
    }
    
    cout << cnt;
}