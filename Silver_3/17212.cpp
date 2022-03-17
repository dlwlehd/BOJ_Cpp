#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

int main() {
    input();
    int n;
    cin >> n;
    int d[100002];
    d[1] = d[2] = d[5] = d[7] = 1;
    for (int i = 3; i <= n; i++) {
        if (i - 1 >= 0) d[i] = d[i - 1] + 1;
        if (i - 2 >= 0) d[i] = min(d[i - 2] + 1, d[i]);
        if (i - 5 >= 0) d[i] = min(d[i - 5] + 1, d[i]);
        if (i - 7 >= 0) d[i] = min(d[i - 7] + 1, d[i]);
    }
    cout << d[n];
}