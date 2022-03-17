#include <bits/stdc++.h>

using namespace std;
int n, m;
int pSum[100002] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pSum[i + 1] = pSum[i] + x;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << pSum[b] - pSum[a - 1] << "\n";
    }
}