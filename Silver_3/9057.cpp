#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
}

string add(string a, string b) {
    int aSize = a.size();
    int bSize = b.size();

    int rest = 0;
    string res = "";

    while (aSize > 0 || bSize > 0) {
        int partA = 0;
        if (aSize > 0) {
            partA = a[--aSize] - '0';
        }

        int partB = 0;
        if (bSize > 0) {
            partB = b[--bSize] - '0';
        }

        int partR = partA + partB + rest;
        rest = partR / 10;
        partR %= 10;

        res += (partR + '0');
    }

    string ans = "";
    if (rest > 0) ans = "1";
    for (int i = res.size() - 1; i >= 0; i--) ans += res[i];
    return ans;
}

int main() {
    input();
    int t;
    cin >> t;
    string a[70];
    a[0] = "1";
    a[1] = "1";
    a[2] = "2";
    a[3] = "4";
    for (int i = 4; i < 70; i++) {
        a[i] = add(a[i - 1], a[i - 2]);
        a[i] = add(a[i], a[i - 3]);
        a[i] = add(a[i], a[i - 4]);
    }

    while (t--) {
        int n;
        cin >> n;
        cout << a[n] << "\n";
    }
}
