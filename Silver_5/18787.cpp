#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n >> a >> b;
    int res = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (!flag) {
                flag = 1;
                res++;
            }
        } else {
            flag = 0;
        }
    }
    cout << res;
}