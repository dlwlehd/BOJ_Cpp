#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int aw = 0, bw = 0, ab = 0, bb = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 'W') aw++;
            if (b[i] == 'W') bw++;
        }
        int diff = abs(aw - bw);
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) pos++;
        }
        pos -= diff;
        pos /= 2;
        cout << diff + pos << "\n";
    }
}