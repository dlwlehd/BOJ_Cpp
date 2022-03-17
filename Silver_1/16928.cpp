#include <bits/stdc++.h>

using namespace std;

int nxt[102];
int d[102];

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}


int main() {
    input();
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 100; i++) {
        nxt[i] = i;
        d[i] = -1;
    }

    for (int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        nxt[x] = y;
    }

    d[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int y = x + i;
            if (y > 100) continue;
            y = nxt[y];
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    cout << d[100];
}