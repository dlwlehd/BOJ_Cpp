#include <bits/stdc++.h>
using namespace std;

string s;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

void cover(int i, int mode) {
    if (mode == 0) {
        for (int a = i; a < i + 4; a++) {
            s[a] = 'A';
        }
    }

    if (mode == 1) {
        for (int a = i; a < i + 2; a++) {
            s[a] = 'B';
        }
    }
}

int main() {
    input();
    cin >> s;

    int n = s.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {

            if (cnt % 2 == 1) {
                cout << -1;
                return 0;
            }

            int idx = i - cnt;
            while (cnt > 0) {
                if (cnt > 3) {
                    cover(idx, 0);
                    idx += 4;
                    cnt -= 4;
                }
                else {
                    cover(idx, 1);
                    idx += 2;
                    cnt -= 2;
                }
            }

            cnt = 0;
        }
        else cnt++;
    }

    if (cnt > 0) {

        if (cnt % 2 == 1) {
            cout << -1;
            return 0;
        }
        int idx = n - cnt;

        while (cnt > 0) {
            if (cnt > 3) {
                cover(idx, 0);
                idx += 4;
                cnt -= 4;
            }
            else {
                cover(idx, 1);
                idx += 2;
                cnt -= 2;
            }
        }
    }

    cout << s;
}