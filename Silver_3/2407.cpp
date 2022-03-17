#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
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
    int n, m;
    cin >> n >> m;
    string a[102][102];
    for (int i = 1; i <= n; i++) {
        a[i][0] = a[i][i] = "1";
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] = add(a[i - 1][j], a[i - 1][j - 1]);
        }
    }
    cout << a[n][m];
}
