#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n >> m;
    unordered_set<string> S;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        S.insert(x);
    }
    while (m--) {
        string s;
        cin >> s;
        if (S.count(s)) cnt++;
    }

    cout << cnt;
}