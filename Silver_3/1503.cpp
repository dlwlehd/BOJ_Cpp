#include <bits/stdc++.h>
using namespace std;

int n, m;
bool s[1002];
int res = 987654321;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main(void) {

    input();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s[x] = 1;
    }

    for (int i = 1; i <= 1002; i++) {
        for (int j = 1; j <= 1002; j++) {
            for (int k = 1; k <= 1002; k++) {
                if (s[i] || s[j] || s[k]) continue;

                res = min(res,abs(n - i * j * k));
                if (res == 0) {
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    cout << res;
}