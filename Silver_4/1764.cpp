#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> m;
    vector<string> a;
    set<string> b, res;
    
    for(int i = 0; i < n; i++) {
        string x;
        cin >> x;
        a.push_back(x);
    }
    
    for(int i = 0; i < m; i++) {
        string x;
        cin >> x;
        b.insert(x);
    }
    
    for (int i = 0; i < n; i++) {
        if (b.count(a[i])) {
            res.insert(a[i]);
            cnt++;
        }
    }
    
    cout << cnt << "\n";
    for (auto i : res) cout << i << "\n";
}