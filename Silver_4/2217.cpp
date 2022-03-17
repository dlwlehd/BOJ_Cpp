#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> n;
    vector<int> rope(n);
    for (int i = 0; i < n; i++) {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end(), greater<>());

    int res = rope[0];
    int cap = 2;
    for (int i = 1; i < n; i++) {
        res = max(res, cap * rope[i]);
        cap++;
    }

    cout << res;
}