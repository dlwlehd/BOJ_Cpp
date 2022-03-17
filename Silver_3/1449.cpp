#include <bits/stdc++.h>
using namespace std;

int n, l, cnt = 1;
int leak[1002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> leak[i];
    }

    sort(leak, leak + n);

    int st = leak[0];
    for (int i = 1; i < n; i++) {
        if (leak[i] - st + 1 > l) {
            cnt++;
            st = leak[i];
        }
    }
    cout << cnt;
}