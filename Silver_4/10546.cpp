#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int n; cin >> n;
    unordered_set<string> S;
    for (int i = 1; i < 2 * n; i++) {
        string s; cin >> s;
        if (S.count(s)) S.erase(s);
        else S.insert(s);
    }
    cout << *S.begin();
}