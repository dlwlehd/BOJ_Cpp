#include <bits/stdc++.h>
using namespace std;

int t;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        int cnt0 = 0, cnt1 = 0, res = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) {
                if (x[i] == '0') cnt0++;
                else cnt1++;
            }
        }

        if (cnt0 > cnt1) {
            res += cnt1;
            cnt0 -= cnt1;
            res += cnt0;
        }
        else {
            res += cnt0;
            cnt1 -= cnt0;
            res += cnt1;
        }

        cout << res << "\n";
    }
}